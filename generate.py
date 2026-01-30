#!/usr/bin/env python3
"""
FEB CAN Library Generator

This script generates the FEB_CAN.dbc file from Python message definitions.
Run via ./generate_can.sh rather than directly.

Usage:
    python generate.py                  # Generate DBC file (default)
    python generate.py -l, --list       # List all messages with their IDs
    python generate.py -i, --ids        # Show frame ID allocation map
    python generate.py -v, --validate   # Validate message registry
    python generate.py -h, --help       # Show help
"""
import cantools
import sys
from typing import Callable, Dict, Tuple

# CAN message modules
import bms_messages as bms_msg
import pcu_messages as pcu_msg
import dash_messages as dash_msg
import lvpdb_messages as lvpdb_msg
import dcu_message as dcu_msg
import sensor_nodes_messsages as sensor_msg
import dart_messages as dart_msg
import iv_meter_messages as iv_meter_msg
import ping_pong_messages as ping_pong_msg
import res_messages as res_msg

# =============================================================================
# MESSAGE REGISTRY
# =============================================================================
# Each entry maps: frame_id -> (message_function, description)
# Frame IDs are grouped by board/subsystem with reserved ranges for expansion.
#
# ID ALLOCATION STRATEGY:
#   0x00-0x08:  BMS messages (5 used, 4 reserved)
#   0x09-0x0F:  PCU safety-critical (brake, BSPD) (2 used, 5 reserved)
#   0x10-0x15:  DASH messages (1 used, 5 reserved)
#   0x16-0x1D:  LVPDB messages (3 used, 5 reserved)
#   0x1E-0x2C:  Sensor node messages (8 used, 7 reserved)
#   0x2D-0x33:  DART messages (2 used, 5 reserved)
#   0x34-0x3F:  TPS chip messages (4 used, 8 reserved)
#   0xC0-0xCF:  PCU RMS commands (2 used, 14 reserved)
#   0xD0-0xDF:  Heartbeat messages (6 used, 10 reserved)
#   0xE0-0xEF:  Debug/test messages (4 used, 12 reserved)
#   0xFF:       PCU raw ADC
# =============================================================================

MESSAGE_REGISTRY: Dict[int, Tuple[Callable[[int], cantools.db.Message], str]] = {
    # ----- BMS Messages (0x00-0x08) -----
    0x00: (bms_msg.get_bms_state, "BMS state machine status"),
    0x01: (bms_msg.get_bms_cell_data, "BMS individual cell data"),
    0x02: (bms_msg.get_accumulator_voltage, "Accumulator pack voltage"),
    0x03: (bms_msg.get_accumulator_temperature, "Accumulator pack temperature"),
    0x04: (bms_msg.get_accumulator_faults, "Accumulator fault flags"),
    # 0x05-0x08: Reserved for future BMS messages

    # ----- PCU Safety Messages (0x09-0x0F) -----
    0x09: (pcu_msg.normalized_brake, "Normalized brake pressure"),
    0x0A: (pcu_msg.bspd, "BSPD state"),
    # 0x0B-0x0F: Reserved for future PCU safety messages

    # ----- DASH Messages (0x10-0x15) -----
    0x10: (dash_msg.get_dash_buttons, "Dashboard buttons and switches"),
    # 0x11-0x15: Reserved for future DASH messages

    # ----- LVPDB Messages (0x16-0x1D) -----
    0x16: (lvpdb_msg.get_lvpdb_flag_bus_voltage_lv_current, "LVPDB flags and voltages"),
    0x17: (lvpdb_msg.get_lvpdb_cp_af_rf_sh_current, "LVPDB pump/fan currents"),
    0x18: (lvpdb_msg.get_lvpdb_L_AS_AB_current, "LVPDB autonomous system currents"),
    # 0x19-0x1D: Reserved for future LVPDB messages

    # ----- Sensor Node Messages (0x1E-0x2C) -----
    0x1E: (sensor_msg.get_LinPot_Front, "Front linear potentiometer"),
    0x1F: (sensor_msg.get_LinPot_Rear, "Rear linear potentiometer"),
    0x20: (sensor_msg.get_front_left_tire_temp_data, "Front left tire temperature"),
    0x21: (sensor_msg.get_front_right_tire_temp_data, "Front right tire temperature"),
    0x22: (sensor_msg.get_rear_left_tire_temp_data, "Rear left tire temperature"),
    0x23: (sensor_msg.get_rear_right_tire_temp_data, "Rear right tire temperature"),
    0x24: (sensor_msg.get_wss_data_front, "Front wheel speed sensors"),
    0x25: (sensor_msg.get_wss_data_rear, "Rear wheel speed sensors"),
    # 0x26-0x2C: Reserved for future sensor messages

    # ----- DART Messages (0x2D-0x33) -----
    0x2D: (dart_msg.get_measured_fan_speeds_1234, "DART fan speeds 1-4"),
    0x2E: (dart_msg.get_measured_fan_speeds_5, "DART fan speed 5"),
    # 0x2F-0x33: Reserved for future DART messages

    # ----- TPS Chip Messages (0x34-0x3F) -----
    0x34: (bms_msg.get_tps_voltage_current, "BMS TPS voltage/current"),
    0x35: (pcu_msg.get_tps_voltage_current, "PCU TPS voltage/current"),
    0x36: (dash_msg.get_tps_voltage_current, "DASH TPS voltage/current"),
    0x37: (dcu_msg.get_tps_voltage_current, "DCU TPS voltage/current"),
    # 0x38-0x3F: Reserved for future TPS messages

    # ----- RMS/Inverter Messages (0xC0-0xCF) -----
    0xC0: (pcu_msg.rms_command_msg, "RMS inverter command"),
    0xC1: (pcu_msg.rms_param_msg, "RMS inverter parameters"),
    # 0xC2-0xCF: Reserved for future RMS messages

    # ----- Heartbeat Messages (0xD0-0xDF) -----
    0xD0: (pcu_msg.get_pcu_heartbeat, "PCU heartbeat"),
    0xD1: (dash_msg.get_dash_heartbeat, "DASH heartbeat"),
    0xD2: (lvpdb_msg.get_lvpdb_heartbeat, "LVPDB heartbeat"),
    0xD3: (dcu_msg.get_dcu_heartbeat, "DCU heartbeat"),
    0xD4: (sensor_msg.get_front_sensor_heartbeat, "Front sensor node heartbeat"),
    0xD5: (sensor_msg.get_rear_sensor_heartbeat, "Rear sensor node heartbeat"),
    # 0xD6-0xDF: Reserved for future heartbeats

    # ----- Debug/Test Messages (0xE0-0xEF) -----
    0xE0: (ping_pong_msg.get_ping_pong_counter1, "Ping pong counter 1"),
    0xE1: (ping_pong_msg.get_ping_pong_counter2, "Ping pong counter 2"),
    0xE2: (ping_pong_msg.get_ping_pong_counter3, "Ping pong counter 3"),
    0xE3: (ping_pong_msg.get_ping_pong_counter4, "Ping pong counter 4"),
    # 0xE4-0xEF: Reserved for future debug messages

    # ----- Miscellaneous (0xF0-0xFF) -----
    0xFF: (pcu_msg.get_raw_acc, "PCU raw accelerator ADC"),
}

# Frame ID allocation ranges for documentation and validation
ID_RANGES = [
    (0x00, 0x08, "BMS"),
    (0x09, 0x0F, "PCU Safety"),
    (0x10, 0x15, "DASH"),
    (0x16, 0x1D, "LVPDB"),
    (0x1E, 0x2C, "Sensor Nodes"),
    (0x2D, 0x33, "DART"),
    (0x34, 0x3F, "TPS Chips"),
    (0xC0, 0xCF, "RMS/Inverter"),
    (0xD0, 0xDF, "Heartbeats"),
    (0xE0, 0xEF, "Debug/Test"),
    (0xF0, 0xFF, "Miscellaneous"),
]


def validate_registry() -> bool:
    """Validate the message registry for common errors."""
    errors = []

    # Check for duplicate functions (same function registered twice)
    seen_funcs = {}
    for frame_id, (func, desc) in MESSAGE_REGISTRY.items():
        func_name = f"{func.__module__}.{func.__name__}"
        if func_name in seen_funcs:
            errors.append(
                f"Duplicate function: {func_name} at IDs "
                f"0x{seen_funcs[func_name]:02X} and 0x{frame_id:02X}"
            )
        seen_funcs[func_name] = frame_id

    # Check frame ID is within valid CAN range
    for frame_id in MESSAGE_REGISTRY.keys():
        if frame_id < 0 or frame_id > 0x7FF:
            errors.append(f"Frame ID 0x{frame_id:X} out of valid CAN range (0x000-0x7FF)")

    # Check IDs are within their designated ranges
    all_ids = set(MESSAGE_REGISTRY.keys())
    for start, end, name in ID_RANGES:
        range_ids = [i for i in all_ids if start <= i <= end]
        for fid in range_ids:
            all_ids.discard(fid)

    # Any IDs not in a defined range?
    for fid in all_ids:
        # Find what range it should be in
        found_range = False
        for start, end, name in ID_RANGES:
            if start <= fid <= end:
                found_range = True
                break
        if not found_range:
            errors.append(f"Frame ID 0x{fid:02X} is not within any defined range")

    if errors:
        for err in errors:
            print(f"[ERROR] {err}", file=sys.stderr)
        return False
    return True


def list_messages() -> None:
    """Print all registered messages with their IDs."""
    print(f"{'ID':<8} {'Message Name':<45} {'Description'}")
    print("-" * 95)
    for frame_id in sorted(MESSAGE_REGISTRY.keys()):
        func, desc = MESSAGE_REGISTRY[frame_id]
        msg = func(frame_id)
        print(f"0x{frame_id:02X}     {msg.name:<45} {desc}")
    print(f"\nTotal: {len(MESSAGE_REGISTRY)} messages")


def show_id_map() -> None:
    """Show frame ID allocation map with usage statistics."""
    print("Frame ID Allocation Map")
    print("=" * 60)

    all_ids = sorted(MESSAGE_REGISTRY.keys())
    total_used = 0
    total_available = 0

    for start, end, name in ID_RANGES:
        used = [i for i in all_ids if start <= i <= end]
        capacity = end - start + 1
        available = capacity - len(used)
        total_used += len(used)
        total_available += available

        print(f"\n{name} (0x{start:02X}-0x{end:02X}): {len(used)}/{capacity} used")
        if used:
            for fid in used:
                func, desc = MESSAGE_REGISTRY[fid]
                msg = func(fid)
                print(f"  0x{fid:02X}: {msg.name}")
        else:
            print("  (none)")

    print(f"\n{'=' * 60}")
    print(f"Total: {total_used} messages, {total_available} IDs available")


def generate_dbc() -> None:
    """Generate the DBC file from the message registry."""
    messages = []
    for frame_id in sorted(MESSAGE_REGISTRY.keys()):
        func, _ = MESSAGE_REGISTRY[frame_id]
        msg = func(frame_id)
        messages.append(msg)

    db = cantools.db.Database(messages=messages)
    cantools.db.dump_file(db, "gen/FEB_CAN.dbc")
    print(f"Generated gen/FEB_CAN.dbc with {len(messages)} messages")


def show_help() -> None:
    """Print help message."""
    print("FEB CAN Library Generator")
    print("")
    print("Usage: python generate.py [option]")
    print("")
    print("Options:")
    print("  (none)              Generate DBC file (default)")
    print("  -l, --list          List all messages with their IDs")
    print("  -i, --ids           Show frame ID allocation map")
    print("  -v, --validate      Validate message registry only")
    print("  -h, --help          Show this help")
    print("")
    print("Note: Run via ./generate_can.sh for full generation pipeline.")


def main():
    """Main entry point supporting multiple commands."""
    if len(sys.argv) > 1:
        cmd = sys.argv[1]
        if cmd in ("-l", "--list"):
            list_messages()
            return
        elif cmd in ("-i", "--ids"):
            show_id_map()
            return
        elif cmd in ("-v", "--validate"):
            if validate_registry():
                print("Registry validation passed!")
            else:
                sys.exit(1)
            return
        elif cmd in ("-h", "--help"):
            show_help()
            return
        else:
            print(f"Unknown option: {cmd}", file=sys.stderr)
            show_help()
            sys.exit(1)

    # Default: generate DBC
    if not validate_registry():
        sys.exit(1)
    generate_dbc()


if __name__ == "__main__":
    main()
