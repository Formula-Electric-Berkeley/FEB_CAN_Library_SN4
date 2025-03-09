# Libraries
import cantools

# CAN messages
import bms_messages as bms_msg
import ping_pong_messages as ping_pong_msg
import lvpdb_messages as lvpdb_msg
import iv_meter_messages as iv_meter_msg

# List of functions, used to generate CAN messages.
MESSAGE_GEN_LIST = [
    bms_msg.get_bms_cell_voltage,
    iv_meter_msg.get_iv_meter_data,
    lvpdb_msg.get_lvpdb_flag_bus_voltage,
    lvpdb_msg.get_lvpdb_lv_cp_current,
    lvpdb_msg.get_lvpdb_af_rf_current,
    lvpdb_msg.get_lvpdb_sh_l_current,
    lvpdb_msg.get_lvpdb_as_ab_current,
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
