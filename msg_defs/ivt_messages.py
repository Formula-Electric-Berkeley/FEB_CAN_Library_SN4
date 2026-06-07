import cantools

# Isabellenhutte IVT-S current/voltage/temperature sensor.
#
# The IVT-S broadcasts each measurement in its own 6-byte standard frame:
#   - bytes 0-1: message counter / header (big-endian)
#   - bytes 2-5: signed int32 measurement value (big-endian)
#
# Raw measurement units, applied by the BMS consumer (BMS/Core/User/Src/FEB_CAN_IVT.c):
#   - current      -> mA
#   - voltage 1-3  -> mV
#   - temperature  -> 0.1 degC
#
# The signal is kept raw (scale=1) here; the BMS applies the unit conversion and
# FEB sign convention in C so behavior is identical to the hand-rolled parser this
# replaces. Big-endian start bits follow the repo's Motorola "sawtooth" convention
# (byte N MSB -> start = N*8 + 7), matching msg_defs/pcu_messages.py.


def _ivt_message(frame_id: int, msg_name: str, value_name: str, comment: str):
    counter = cantools.db.Signal(
        name="counter",
        start=7,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )

    value = cantools.db.Signal(
        name=value_name,
        start=23,
        length=32,
        byte_order="big_endian",
        is_signed=True,
    )

    return cantools.db.Message(
        frame_id=frame_id,
        name=msg_name,
        length=6,
        signals=[counter, value],
        comment=comment,
        strict=True,
    )


def get_ivt_current(frame_id: int):
    return _ivt_message(frame_id, "IVTCurrent", "current",
                        "Isabellenhutte IVT-S pack current (raw int32, mA).")


def get_ivt_voltage_1(frame_id: int):
    return _ivt_message(frame_id, "IVTVoltage1", "voltage1",
                        "Isabellenhutte IVT-S voltage 1 / pack voltage (raw int32, mV).")


def get_ivt_voltage_2(frame_id: int):
    return _ivt_message(frame_id, "IVTVoltage2", "voltage2",
                        "Isabellenhutte IVT-S voltage 2 (raw int32, mV).")


def get_ivt_voltage_3(frame_id: int):
    return _ivt_message(frame_id, "IVTVoltage3", "voltage3",
                        "Isabellenhutte IVT-S voltage 3 (raw int32, mV).")


def get_ivt_temperature(frame_id: int):
    return _ivt_message(frame_id, "IVTTemperature", "temperature",
                        "Isabellenhutte IVT-S temperature (raw int32, 0.1 degC).")
