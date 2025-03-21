# Libraries
import cantools

# CAN messages
import bms_messages as bms_msg
import ping_pong_messages as ping_pong_msg
import lvpdb_messages as lvpdb_msg
import iv_meter_messages as iv_meter_msg
import dash_messages as dash_msg
import dart_messages as dart_msg
import pcu_messages as pcu_msg

# List of functions, used to generate CAN messages.
MESSAGE_GEN_LIST = [
    #0x0-0x3
    bms_msg.get_bms_state,
    bms_msg.get_bms_cell_data,
    bms_msg.get_accumulator_voltage, 
    bms_msg.get_accumulator_temperature,
    
    #0x4-0x5
    pcu_msg.normalized_brake,
    pcu_msg.bspd,
    
    #0x6
    dash_msg.get_dash_buttons,
    
    #0x7-0x9
    lvpdb_msg.get_lvpdb_flag_bus_voltage_lv_current,
    lvpdb_msg.get_lvpdb_cp_af_rf_sh_current,
    lvpdb_msg.get_lvpdb_L_AS_AB_current,

    #finalize sensor node here

    #finalize all board tps here
    #pcu_msg.current,

    #0x30 - 0x31
    dart_msg.get_measured_fan_speeds_1234,
    dart_msg.get_measured_fan_speeds_5,
    
    #0xa5-0xa7
    #RMS messages from inverter
    
    #0xc0-0xc1
    pcu_msg.rms_param_msg,
    pcu_msg.rms_command_msg, 

    #0xe0-0xe0
    ping_pong_msg.get_ping_pong_counter1,
    ping_pong_msg.get_ping_pong_counter2,
    ping_pong_msg.get_ping_pong_counter3,
    ping_pong_msg.get_ping_pong_counter4,
    
    #iv_meter_msg.get_iv_meter_data, # not being used SN4
]

# List of priority assignments for each CAN message above
MESSAGE_GEN_ID = [
    #BMS
    0, 1, 2, 3, 

    #PCU break and BSDPD
    4, 5,

    #DASH
    6, 

    #LVPDB
    7, 8, 9, 

    #Sensor Node

    #TPS

    #DART
    30, 31,

    #PCU RMS (Inverter) Parameter and Command
    192, 193,

    #PING PONG
    224, 225, 226, 227
]

def main():
    # Load CAN messages
    messages = []
    for i in range(len(MESSAGE_GEN_LIST)):
        msg = MESSAGE_GEN_LIST[i](MESSAGE_GEN_ID[i])
        messages.append(msg)
    
    # Generate DBC file
    db = cantools.db.Database(messages=messages)
    cantools.db.dump_file(db, "gen/FEB_CAN.dbc")

if __name__ == "__main__":
    main()
