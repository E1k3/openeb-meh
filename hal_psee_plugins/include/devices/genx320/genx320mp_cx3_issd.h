
/**********************************************************************************************************************
 * Copyright (c) Prophesee S.A. - All Rights Reserved                                                                 *
 *                                                                                                                    *
 * Subject to Prophesee Metavision Licensing Terms and Conditions ("License T&C's").                                  *
 * You may not use this file except in compliance with these License T&C's.                                           *
 * A copy of these License T&C's is located in the "licensing" folder accompanying this file.                         *
 **********************************************************************************************************************/

// ISSD sequences generated by psee_issd_convert.
// Parameters:
// issd_csv_format_version=1.1
// system=PseeEvk3GenX320
// operator=Prophesee
// dry_run=False
// no_system=False
// strip_prefix=False
// sensor_version=None
// args=-s evk3_genx320_cd
// sensor=GenX320Sensor
// date=2024-01-29T17:38:04
// issd_trace_recoder_version=0.0.1.dev2+g633913d82.d20240126
// psee_sensor_lib_version=3.5.1.109+gda565e888.d20240024
// psee_biases_genx320_version=2.0.0
// issd_data_format_version=1.0

#include <vector>

namespace Metavision {

// clang-format off

const std::vector<RegisterOperation> issd_genx320mp_cx3_init = {
    RegisterOperation::Write(0x0000001C, 0x00000001),
    RegisterOperation::Delay(10000),
    RegisterOperation::Write(0x0000F004, 0x00000001),
    RegisterOperation::Delay(10000),
    RegisterOperation::Write(0x0000F004, 0x00000000),
    RegisterOperation::Delay(10000),
    // RegisterOperation::Read(0x0000F010, 0xCAFEBABE, 0xFFFFFFFF),
    RegisterOperation::Write(0x0000B010, 0x00000000),
    RegisterOperation::Write(0x0000B000, 0x1000C003),
    RegisterOperation::Write(0x0000704C, 0x00002710),
    RegisterOperation::Write(0x00007100, 0x0000FFFF),
    RegisterOperation::Write(0x000000B8, 0x00000020),
    RegisterOperation::Write(0x000000C0, 0x000000B8),
    RegisterOperation::Write(0x0000B000, 0x1000C003),
    RegisterOperation::Write(0x0000B000, 0x10008803),
    RegisterOperation::Write(0x0000B024, 0x80003E80),
    RegisterOperation::Write(0x00001208, 0x00000030),
    RegisterOperation::Delay(200),
    RegisterOperation::Write(0x00001104, 0x01010019),
    RegisterOperation::Write(0x00001128, 0x01010019),
    RegisterOperation::Write(0x0000110C, 0x01010015),
    RegisterOperation::Write(0x00001130, 0x01010014),
    RegisterOperation::Write(0x00001000, 0x0301003D),
    RegisterOperation::Write(0x00001004, 0x03010022),
    RegisterOperation::Write(0x00001008, 0x0101003F),
    RegisterOperation::Write(0x00001100, 0x03010028),
    RegisterOperation::Write(0x00001104, 0x01010019),
    RegisterOperation::Write(0x00001108, 0x01010033),
    RegisterOperation::Write(0x0000110C, 0x0101001C),
    RegisterOperation::Write(0x00001110, 0x01010039),
    RegisterOperation::Write(0x00001114, 0x0309000A),
    RegisterOperation::Write(0x00001118, 0x03010038),
    RegisterOperation::Write(0x0000111C, 0x03000074),
    RegisterOperation::Write(0x00001120, 0x010000A4),
    RegisterOperation::Write(0x00001208, 0x00000035)
};

const std::vector<RegisterOperation> issd_genx320mp_cx3_start = {
    // DIGITAL START sequence -- begin
    // DIGITAL: MIPI enable
    RegisterOperation::Write(0x0000B000, 0x10008803),
    // DIGITAL: RO exit LowPower + timebase enable
    RegisterOperation::Write(0x00009028, 0x00000000),
    RegisterOperation::WriteField(0x00009008, 0x00000195, 0x00000001),
    // DIGITAL START sequence -- end
    // ANALOG START sequence -- begin
    RegisterOperation::Delay(1),
    RegisterOperation::Write(0x0000002C, 0x0022C724),
    RegisterOperation::Write(0x00000000, 0x00000C02),
    RegisterOperation::Delay(1),
    // ANALOG START sequence -- end
};

const std::vector<RegisterOperation> issd_genx320mp_cx3_stop = {
    // ANALOG STOP sequence -- begin
    RegisterOperation::Write(0x00000000, 0x00000802),
    RegisterOperation::Write(0x0000002C, 0x00200624),
    // ANALOG STOP sequence -- end
    // DIGITAL STOP sequence -- begin
    // DIGITAL: Enter Low Power
    RegisterOperation::Write(0x00009028, 0x00000002),
    RegisterOperation::Delay(1000),
    // DIGITAL: Timebase disable
    RegisterOperation::WriteField(0x00009008, 0x00000194, 0x00000001),
    // DIGITAL: MIPI DPHY disable
    RegisterOperation::Write(0x0000B000, 0x10008804),
    // DIGITAL STOP sequence -- end
};

const std::vector<RegisterOperation> issd_genx320mp_cx3_destroy = {
    // ANALOG DESTROY sequence -- begin
    RegisterOperation::Delay(1),
    // Disabling the PMU...
    RegisterOperation::Write(0x00000070, 0x0000051C),
    RegisterOperation::Write(0x0000A004, 0x00600054),
    RegisterOperation::Write(0x0000A008, 0x00600084),
    RegisterOperation::Write(0x0000005C, 0x00000080),
    RegisterOperation::Write(0x0000005C, 0x00000080),
    RegisterOperation::Write(0x0000A01C, 0x0013601C),
    RegisterOperation::Write(0x0000A000, 0x00040400),
    // Disabling the PMU...done!
    RegisterOperation::Delay(1),
    // ANALOG DESTROY sequence -- end
    // DIGITAL DESTROY sequence -- begin
    // DIGITAL: MIPI DPHY and PLL Power Down
    RegisterOperation::Write(0x0000B030, 0x00000013),
    RegisterOperation::Write(0x0000B00C, 0x00000102),
    RegisterOperation::Write(0x0000B030, 0x00000010),
    RegisterOperation::Write(0x0000B00C, 0x00000002),
    RegisterOperation::Write(0x0000A01C, 0x0003601C),
    RegisterOperation::Write(0x0000004C, 0x00204E20),
    RegisterOperation::Write(0x0000B030, 0x00000000),
    RegisterOperation::Write(0x0000A01C, 0x0003601C),
    RegisterOperation::Write(0x0000A000, 0x00000400),
    RegisterOperation::Write(0x00000204, 0x00000E75),
    RegisterOperation::Write(0x00000204, 0x00000E74),
    RegisterOperation::Write(0x00000214, 0x000184A0),
    // DIGITAL DESTROY sequence -- end
};

Issd issd_genx320mp_cx3_sequence = Issd{
    issd_genx320mp_cx3_init,
    issd_genx320mp_cx3_start,
    issd_genx320mp_cx3_stop,
    issd_genx320mp_cx3_destroy,
};

} // namespace Metavision

// clang-format on
