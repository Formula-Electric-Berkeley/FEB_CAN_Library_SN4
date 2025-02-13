# Libraries
import cantools

# CAN messages
import bms_messages as bms_msg

# List of functions, used to generate CAN messages.
MESSAGE_GEN_LIST = [
    bms_msg.get_bms_cell_voltage
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
