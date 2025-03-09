
import cantools
from cantools.database.conversion import BaseConversion

def get_dash_buttons(frame_id: int):
    buzzer_state = cantools.db.Signal(
        name="buzzer_state",
        start=0,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    button1 = cantools.db.Signal(
        name="button1_ready_to_drive",
        start=1,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    button2 = cantools.db.Signal(
        name="button2",
        start=2,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    button3 = cantools.db.Signal(
        name="button3",
        start=3,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    button4 = cantools.db.Signal(
        name="button4",
        start=4,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    switch1 = cantools.db.Signal(
        name="coolant_pump_switch",
        start=5,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    switch2 = cantools.db.Signal(
        name="radiator_fan_switch",
        start=6,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    switch3 = cantools.db.Signal(
        name="accumulator_fan_switch",
        start=7,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )
    

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_Dash_Message",
        length=1,
        signals=[buzzer_state, button1, button2, button3, button4, switch1, switch2, switch3],
        comment="Dash message",
        strict=True
    )

    return msg
