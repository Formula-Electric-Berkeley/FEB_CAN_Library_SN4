import cantools
from cantools.database.conversion import BaseConversion

def get_ping_pong_counter(frame_id: int):
    counter_signal = cantools.db.Signal(
        name="counter",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_PING_PONG_counter",
        length=8,
        signals=[counter_signal],
        comment="PING PONG counter.",
        strict=True
    )

    return msg
