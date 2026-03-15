import cantools
from cantools.database.conversion import BaseConversion

def get_res_state(frame_id: int):
    res_state = cantools.db.Signal(
        name="res_state",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="res_state",
        length=2,
        signals=[res_state],
        comment="RES message for RES state.",
        strict=True
    )

    return msg


def get_res_status(frame_id: int):
    relay_state = cantools.db.Signal(
        name="relay_state",
        start=0,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    ts_activation = cantools.db.Signal(
        name="ts_activation",
        start=1,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_critical = cantools.db.Signal(
        name="bms_critical",
        start=2,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    shutdown_open_fault = cantools.db.Signal(
        name="shutdown_open_fault",
        start=3,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    emergency_latched = cantools.db.Signal(
        name="emergency_latched",
        start=4,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    relay_enable_allowed = cantools.db.Signal(
        name="relay_enable_allowed",
        start=5,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    tps_power_good = cantools.db.Signal(
        name="tps_power_good",
        start=6,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    tps_alert = cantools.db.Signal(
        name="tps_alert",
        start=7,
        length=1,
        byte_order="little_endian",
        is_signed=False,
    )

    status_counter = cantools.db.Signal(
        name="status_counter",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="res_status",
        length=2,
        signals=[
            relay_state,
            ts_activation,
            bms_critical,
            shutdown_open_fault,
            emergency_latched,
            relay_enable_allowed,
            tps_power_good,
            tps_alert,
            status_counter,
        ],
        comment="RES_EBS safety and relay status.",
        strict=True,
    )

    return msg
