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
    bms_msg.get_bms_cell_voltage,
    iv_meter_msg.get_iv_meter_data,
    lvpdb_msg.get_lvpdb_flag_bus_voltage_lv_current,
    lvpdb_msg.get_lvpdb_cp_af_rf_sh_current,
    lvpdb_msg.get_lvpdb_L_AS_AB_current,
    pcu_msg.normalized_brake,
    pcu_msg.rms_param_msg,
    pcu_msg.rms_command_msg,
    pcu_msg.bspd,
    pcu_msg.current,
    dash_msg.get_dash_buttons,
    dart_msg.get_measured_fan_speeds,
    ping_pong_msg.get_ping_pong_counter1,
    ping_pong_msg.get_ping_pong_counter2,
    ping_pong_msg.get_ping_pong_counter3,
    ping_pong_msg.get_ping_pong_counter4,
]

def main():
    # Load CAN messages
    messages = []
    for i in range(len(MESSAGE_GEN_LIST)):
        msg = MESSAGE_GEN_LIST[i](i)
        messages.append(msg)
    
    # Generate DBC file
    db = cantools.db.Database(messages=messages)
    cantools.db.dump_file(db, "gen/FEB_CAN.dbc")

if __name__ == "__main__":
    main()
