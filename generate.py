import cantools

import bms_messages as bms_msg

MESSAGE_GEN_LIST = [
    bms_msg.get_bms_cell_voltage
]

def main():
    messages = []
    for i in range(len(MESSAGE_GEN_LIST)):
        msg = MESSAGE_GEN_LIST[i](i)
        messages.append(msg)
    
    db = cantools.db.Database(messages=messages)
    cantools.db.dump_file(db, "gen/FEB_CAN.dbc")

if __name__ == "__main__":
    main()
