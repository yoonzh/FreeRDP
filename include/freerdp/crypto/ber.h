/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * ASN.1 Basic Encoding Rules (BER)
 *
 * Copyright 2011-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_CRYPTO_BER_H
#define FREERDP_CRYPTO_BER_H

#include <freerdp/api.h>
#include <freerdp/types.h>
#include <freerdp/utils/stream.h>

/* BER type */

/* Class - bits 8 and 7 */
#define BER_CLASS_MASK		0xC0
#define BER_CLASS_UNIV		0x00 /* 0 0 */
#define BER_CLASS_APPL		0x40 /* 0 1 */
#define BER_CLASS_CTXT		0x80 /* 1 0 */
#define BER_CLASS_PRIV		0xC0 /* 1 1 */

/* P/C - bit 6 */
#define BER_PC_MASK		0x20
#define BER_PRIMITIVE		0x00 /* 0 */
#define BER_CONSTRUCT		0x20 /* 1 */

/* Tag - bits 5 to 1 */
#define BER_TAG_MASK		0x1F
#define BER_TAG_BOOLEAN		0x01
#define BER_TAG_INTEGER		0x02
#define BER_TAG_BIT_STRING	0x03
#define BER_TAG_OCTET_STRING	0x04
#define BER_TAG_OBJECT_IDENFIER	0x06
#define BER_TAG_ENUMERATED	0x0A
#define BER_TAG_SEQUENCE	0x10
#define BER_TAG_SEQUENCE_OF	0x10

#define BER_PC(_pc)	(_pc ? BER_CONSTRUCT : BER_PRIMITIVE)

FREERDP_API void ber_read_length(STREAM* s, int* length);
FREERDP_API int ber_write_length(STREAM* s, int length);
FREERDP_API int _ber_skip_length(int length);
FREERDP_API int ber_get_content_length(int length);
FREERDP_API boolean ber_read_universal_tag(STREAM* s, uint8 tag, boolean pc);
FREERDP_API void ber_write_universal_tag(STREAM* s, uint8 tag, boolean pc);
FREERDP_API boolean ber_read_application_tag(STREAM* s, uint8 tag, int* length);
FREERDP_API void ber_write_application_tag(STREAM* s, uint8 tag, int length);
FREERDP_API boolean ber_read_application_tag(STREAM* s, uint8 tag, int* length);
FREERDP_API boolean ber_read_enumerated(STREAM* s, uint8* enumerated, uint8 count);
FREERDP_API void ber_write_enumerated(STREAM* s, uint8 enumerated, uint8 count);
FREERDP_API boolean ber_read_contextual_tag(STREAM* s, uint8 tag, int* length, boolean pc);
FREERDP_API int ber_write_contextual_tag(STREAM* s, uint8 tag, int length, boolean pc);
FREERDP_API int ber_skip_contextual_tag(int length);
FREERDP_API boolean ber_read_sequence_tag(STREAM* s, int* length);
FREERDP_API int ber_write_sequence_tag(STREAM* s, int length);
FREERDP_API int ber_skip_sequence(int length);
FREERDP_API int ber_skip_sequence_tag(int length);
FREERDP_API boolean ber_read_bit_string(STREAM* s, int* length, uint8* padding);
FREERDP_API boolean ber_read_octet_string(STREAM* s, int* length);
FREERDP_API void ber_write_octet_string(STREAM* s, const uint8* oct_str, int length);
FREERDP_API int ber_write_octet_string_tag(STREAM* s, int length);
FREERDP_API int ber_skip_octet_string(int length);
FREERDP_API boolean ber_read_boolean(STREAM* s, boolean* value);
FREERDP_API void ber_write_boolean(STREAM* s, boolean value);
FREERDP_API boolean ber_read_integer(STREAM* s, uint32* value);
FREERDP_API int ber_write_integer(STREAM* s, uint32 value);
FREERDP_API boolean ber_read_integer_length(STREAM* s, int* length);
FREERDP_API int ber_skip_integer(uint32 value);

#endif /* FREERDP_CRYPTO_BER_H */
