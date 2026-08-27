from collections import OrderedDict
import cantools
from cantools.database.conversion import BaseConversion

def get_bms_state(frame_id: int):
    bms_state = cantools.db.Signal(
        name="bms_state",
        start=0,
        length=5,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(
            choices=OrderedDict([
                (0, "BMS_STATE_BOOT"),
                (1, "BMS_STATE_LV_POWER"),
                (2, "BMS_STATE_BUS_HEALTH_CHECK"),
                (3, "BMS_STATE_PRECHARGE"),
                (4, "BMS_STATE_ENERGIZED"),
                (5, "BMS_STATE_DRIVE"),
                (6, "BMS_STATE_BATTERY_FREE"),
                (7, "BMS_STATE_CHARGER_PRECHARGE"),
                (8, "BMS_STATE_CHARGING"),
                (9, "BMS_STATE_BALANCE"),
                (10, "BMS_STATE_FAULT_BMS"),
                (11, "BMS_STATE_FAULT_BSPD"),
                (12, "BMS_STATE_FAULT_IMD"),
                (13, "BMS_STATE_FAULT_CHARGING"),
                (14, "BMS_STATE_COUNT"),
            ])
        )
    )

    ping_lv_nodes = cantools.db.Signal(
        name="ping_lv_nodes",
        start=5,
        length=3,
        byte_order="little_endian",
        is_signed=False,
    )

    relay_state = cantools.db.Signal(
        name="relay_state",
        start=8,
        length=3,
        byte_order="little_endian",
        is_signed=False,
    )

    gpio_sense = cantools.db.Signal(
        name="gpio_sense",
        start=11,
        length=5,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bms_state",
        length=2,
        signals=[bms_state, ping_lv_nodes, relay_state, gpio_sense],
        comment="BMS message for BMS state.",
        strict=True
    )

    return msg

def get_bms_cell_data(frame_id: int):
    bms_flags = cantools.db.Signal(
        name="bms_flags",
        start=0,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_cell = cantools.db.Signal(
        name="bms_cell",
        start=8,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_bank = cantools.db.Signal(
        name="bms_bank",
        start=12,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_voltage = cantools.db.Signal(
        name="bms_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    bms_temperature = cantools.db.Signal(
        name="bms_temperature",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
    )

    bms_send_time = cantools.db.Signal(
        name="bms_send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bms_cell_data",
        length=8,
        signals=[bms_flags, bms_cell, bms_bank, bms_voltage, bms_temperature, bms_send_time],
        comment="BMS message for cell data.",
        strict=True
    )

    return msg

def get_accumulator_voltage(frame_id: int):
    total_pack_voltage = cantools.db.Signal(
        name="total_pack_voltage",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    min_cell_voltage = cantools.db.Signal(
        name="min_cell_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    max_cell_voltage = cantools.db.Signal(
        name="max_cell_voltage",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    send_time = cantools.db.Signal(
        name="send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bms_accumulator_voltage",
        length=8,
        signals=[total_pack_voltage, min_cell_voltage, max_cell_voltage, send_time],
        comment="BMS message for accumulator voltage.",
        strict=True
    )

    return msg

def get_accumulator_temperature(frame_id: int):
    total_pack_voltage = cantools.db.Signal(
        name="average_pack_temperature",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
    )

    min_cell_temperature = cantools.db.Signal(
        name="min_cell_temperature",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
    )

    max_cell_temperature = cantools.db.Signal(
        name="max_cell_temperature",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
    )

    send_time = cantools.db.Signal(
        name="send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bms_accumulator_temperature",
        length=8,
        signals=[total_pack_voltage, min_cell_temperature, max_cell_temperature, send_time],
        comment="BMS message for accumulator temperature.",
        strict=True
    )

    return msg

def get_tps_voltage_current(frame_id: int):    
    bbb_voltage_signal = cantools.db.Signal(
        name="voltage",
        start=0,
        length=16,
        byte_order="little_endian",
    )
    
    bbb_current_signal = cantools.db.Signal(
        name="current",
        start=16,
        length=16,
        byte_order="little_endian",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bbb_tps",
        length=4,
        signals=[bbb_voltage_signal, bbb_current_signal],
        comment="BBB TPS Chip",
        strict=True
    )

    return msg

def get_accumulator_faults(frame_id: int):    
    bms_fault = cantools.db.Signal(
        name="bms_fault",
        start=0,
        length=1,
        byte_order="little_endian",
    )
    
    imd_fault = cantools.db.Signal(
        name="imd_fault",
        start=1,
        length=1,
        byte_order="little_endian",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="accumulator_faults",
        length=1,
        signals=[bms_fault, imd_fault],
        comment="Accumulator Faults",
        strict=True
    )

    return msg

MODULE_COUNT = 10
CELLS_PER_MODULE = 16
SENSORS_PER_MODULE = 41

_PAYLOAD_BITS = 64
_SELECTOR_BITS = 8
VALUES_PER_PAGE = 4
_SLOT_BITS = (_PAYLOAD_BITS - _SELECTOR_BITS) // VALUES_PER_PAGE

VOLTAGE_PAGES_PER_MODULE = -(-CELLS_PER_MODULE // VALUES_PER_PAGE)
TEMP_PAGES_PER_MODULE = -(-SENSORS_PER_MODULE // VALUES_PER_PAGE)

_VOLTAGE_SCALE = 0.0005    # V per LSB
_TEMP_SCALE = 0.1          # degC per LSB


def _page_selector():
    return cantools.db.Signal(
        name="page",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False,
        is_multiplexer=True,
        comment="Page index: selects which cells occupy the four value slots.",
    )


def _slot_start(slot: int) -> int:
    return _SELECTOR_BITS + slot * _SLOT_BITS


def _slot(name: str, slot: int, page: int, *, is_signed: bool,
          scale: float, unit: str):
    return cantools.db.Signal(
        name=name,
        start=_slot_start(slot),
        length=_SLOT_BITS,
        byte_order="little_endian",
        is_signed=is_signed,
        conversion=BaseConversion.factory(scale=scale),
        unit=unit,
        multiplexer_ids=[page],
        multiplexer_signal="page",
    )


def get_cell_voltages(frame_id: int):
    signals = [_page_selector()]

    for module in range(1, MODULE_COUNT + 1):
        for p in range(VOLTAGE_PAGES_PER_MODULE):
            page = (module - 1) * VOLTAGE_PAGES_PER_MODULE + p
            for slot in range(VALUES_PER_PAGE):
                cell = p * VALUES_PER_PAGE + slot + 1
                signals.append(_slot(
                    f"module_{module}_cell_{cell}", slot, page,
                    is_signed=False, scale=_VOLTAGE_SCALE, unit="V",
                ))

    return cantools.db.Message(
        frame_id=frame_id,
        name="bms_cell_voltages",
        length=8,
        signals=signals,
        comment="Accumulator cell voltages, paged via the page multiplexer.",
        strict=True,
    )


def get_cell_temperatures(frame_id: int):
    signals = [_page_selector()]

    for module in range(1, MODULE_COUNT + 1):
        for p in range(TEMP_PAGES_PER_MODULE):
            page = (module - 1) * TEMP_PAGES_PER_MODULE + p
            base = p * VALUES_PER_PAGE
            count = min(VALUES_PER_PAGE, SENSORS_PER_MODULE - base)
            for slot in range(count):
                signals.append(_slot(
                    f"module_{module}_temp_{base + slot + 1}", slot, page,
                    is_signed=True, scale=_TEMP_SCALE, unit="degC",
                ))

    return cantools.db.Message(
        frame_id=frame_id,
        name="bms_cell_temperatures",
        length=8,
        signals=signals,
        comment="Accumulator cell temperatures, paged via the page multiplexer.",
        strict=True,
    )
