// Copyright 2024 bromero
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define USB_POLLING_INTERVAL_MS 1

// Reduce split sync latency for modifier combos
#define FORCED_SYNC_THROTTLE_MS 10
#define QMK_KEYS_PER_SCAN 6

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP
