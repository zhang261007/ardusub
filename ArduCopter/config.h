// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
//
#pragma once

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
//
//  DO NOT EDIT this file to adjust your configuration.  Create your own
//  APM_Config.h and use APM_Config.h.example as a reference.
//
// WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING
///
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// Default and automatic configuration details.
//
// Notes for maintainers:
//
// - Try to keep this file organised in the same order as APM_Config.h.example
//
#include "defines.h"

///
/// DO NOT EDIT THIS INCLUDE - if you want to make a local change, make that
/// change in your local copy of APM_Config.h.
///
#include "APM_Config.h"


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// HARDWARE CONFIGURATION AND CONNECTIONS
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef CONFIG_HAL_BOARD
#error CONFIG_HAL_BOARD must be defined to build ArduCopter
#endif

//////////////////////////////////////////////////////////////////////////////
// HIL_MODE                                 OPTIONAL

#ifndef HIL_MODE
 #define HIL_MODE        HIL_MODE_DISABLED
#endif

#if HIL_MODE != HIL_MODE_DISABLED       // we are in HIL mode
 #undef CONFIG_SONAR
 #define CONFIG_SONAR DISABLED
#endif

#define MAGNETOMETER ENABLED

// run at 400Hz on all systems
# define MAIN_LOOP_RATE    400
# define MAIN_LOOP_SECONDS 0.0025f
# define MAIN_LOOP_MICROS  2500

//////////////////////////////////////////////////////////////////////////////
// FRAME_CONFIG
//
#ifndef FRAME_CONFIG
 # define FRAME_CONFIG   QUAD_FRAME
#endif

#if FRAME_CONFIG == QUAD_FRAME
 # define FRAME_CONFIG_STRING "QUAD"
#elif FRAME_CONFIG == TRI_FRAME
 # define FRAME_CONFIG_STRING "TRI"
#elif FRAME_CONFIG == HEXA_FRAME
 # define FRAME_CONFIG_STRING "HEXA"
#elif FRAME_CONFIG == Y6_FRAME
 # define FRAME_CONFIG_STRING "Y6"
#elif FRAME_CONFIG == OCTA_FRAME
 # define FRAME_CONFIG_STRING "OCTA"
#elif FRAME_CONFIG == OCTA_QUAD_FRAME
 # define FRAME_CONFIG_STRING "OCTA_QUAD"
#elif FRAME_CONFIG == HELI_FRAME
 # define FRAME_CONFIG_STRING "HELI"
#elif FRAME_CONFIG == SINGLE_FRAME
 # define FRAME_CONFIG_STRING "SINGLE"
#elif FRAME_CONFIG == COAX_FRAME
 # define FRAME_CONFIG_STRING "COAX"
#else
 # define FRAME_CONFIG_STRING "UNKNOWN"
#endif

/////////////////////////////////////////////////////////////////////////////////
// TradHeli defaults
#if FRAME_CONFIG == HELI_FRAME
  # define RC_FAST_SPEED                        125
  # define WP_YAW_BEHAVIOR_DEFAULT              WP_YAW_BEHAVIOR_LOOK_AHEAD
  # define THR_MIN_DEFAULT                      0
  # define AUTOTUNE_ENABLED                     DISABLED
#endif

/////////////////////////////////////////////////////////////////////////////////
// Y6 defaults
#if FRAME_CONFIG == Y6_FRAME
  # define RATE_ROLL_P                  0.1f
  # define RATE_ROLL_D                  0.006f
  # define RATE_PITCH_P                 0.1f
  # define RATE_PITCH_D                 0.006f
  # define RATE_YAW_P                   0.150f
  # define RATE_YAW_I                   0.015f
#endif

/////////////////////////////////////////////////////////////////////////////////
// Tri defaults
#if FRAME_CONFIG == TRI_FRAME
  # define RATE_YAW_FILT_HZ             100.0f
#endif

//////////////////////////////////////////////////////////////////////////////
// PWM control
// default RC speed in Hz
#ifndef RC_FAST_SPEED
   #   define RC_FAST_SPEED 490
#endif

//////////////////////////////////////////////////////////////////////////////
// Sonar
//

#ifndef CONFIG_SONAR
 # define CONFIG_SONAR ENABLED
#endif

#ifndef SONAR_ALT_HEALTH_MAX
 # define SONAR_ALT_HEALTH_MAX 3            // number of good reads that indicates a healthy sonar
#endif

#ifndef SONAR_RELIABLE_DISTANCE_PCT
 # define SONAR_RELIABLE_DISTANCE_PCT 0.60f // we trust the sonar out to 60% of it's maximum range
#endif

#ifndef SONAR_GAIN_DEFAULT
 # define SONAR_GAIN_DEFAULT 0.8f           // gain for controlling how quickly sonar range adjusts target altitude (lower means slower reaction)
#endif

#ifndef THR_SURFACE_TRACKING_VELZ_MAX
 # define THR_SURFACE_TRACKING_VELZ_MAX 150 // max vertical speed change while surface tracking with sonar
#endif

#ifndef SONAR_TIMEOUT_MS
 # define SONAR_TIMEOUT_MS  1000            // desired sonar alt will reset to current sonar alt after this many milliseconds without a good sonar alt
#endif

#ifndef SONAR_TILT_CORRECTION               // by disable tilt correction for use of range finder data by EKF
 # define SONAR_TILT_CORRECTION DISABLED
#endif


#ifndef MAV_SYSTEM_ID
 # define MAV_SYSTEM_ID          1
#endif


//////////////////////////////////////////////////////////////////////////////
// Battery monitoring
//
#ifndef FS_BATT_VOLTAGE_DEFAULT
 # define FS_BATT_VOLTAGE_DEFAULT       10.5f       // default battery voltage below which failsafe will be triggered
#endif

#ifndef FS_BATT_MAH_DEFAULT
 # define FS_BATT_MAH_DEFAULT             0         // default battery capacity (in mah) below which failsafe will be triggered
#endif

#ifndef BOARD_VOLTAGE_MIN
 # define BOARD_VOLTAGE_MIN             4.3f        // min board voltage in volts for pre-arm checks
#endif

#ifndef BOARD_VOLTAGE_MAX
 # define BOARD_VOLTAGE_MAX             5.8f        // max board voltage in volts for pre-arm checks
#endif

// prearm GPS hdop check
#ifndef GPS_HDOP_GOOD_DEFAULT
 # define GPS_HDOP_GOOD_DEFAULT         140     // minimum hdop that represents a good position.  used during pre-arm checks if fence is enabled
#endif

// GCS failsafe
#ifndef FS_GCS
 # define FS_GCS                        DISABLED
#endif
#ifndef FS_GCS_TIMEOUT_MS
 # define FS_GCS_TIMEOUT_MS             5000    // gcs failsafe triggers after 5 seconds with no GCS heartbeat
#endif

#ifndef GNDEFFECT_COMPENSATION
 # define GNDEFFECT_COMPENSATION          DISABLED
#endif

// Radio failsafe while using RC_override
#ifndef FS_RADIO_RC_OVERRIDE_TIMEOUT_MS
 # define FS_RADIO_RC_OVERRIDE_TIMEOUT_MS  1000    // RC Radio failsafe triggers after 1 second while using RC_override from ground station
#endif

// Radio failsafe
#ifndef FS_RADIO_TIMEOUT_MS
 #define FS_RADIO_TIMEOUT_MS            500     // RC Radio Failsafe triggers after 500 miliseconds with No RC Input
#endif

#ifndef FS_CLOSE_TO_HOME_CM
 # define FS_CLOSE_TO_HOME_CM               500 // if vehicle within 5m of home, vehicle will LAND instead of RTL during some failsafes
#endif

#ifndef PREARM_DISPLAY_PERIOD
# define PREARM_DISPLAY_PERIOD 30
#endif

// pre-arm baro vs inertial nav max alt disparity
#ifndef PREARM_MAX_ALT_DISPARITY_CM
 # define PREARM_MAX_ALT_DISPARITY_CM       100     // barometer and inertial nav altitude must be within this many centimeters
#endif

// arming check's maximum acceptable accelerometer vector difference (in m/s/s) between primary and backup accelerometers
#ifndef PREARM_MAX_ACCEL_VECTOR_DIFF
  #define PREARM_MAX_ACCEL_VECTOR_DIFF      0.70f    // pre arm accel check will fail if primary and backup accelerometer vectors differ by 0.7m/s/s
#endif

// arming check's maximum acceptable rotation rate difference (in rad/sec) between primary and backup gyros
#ifndef PREARM_MAX_GYRO_VECTOR_DIFF
  #define PREARM_MAX_GYRO_VECTOR_DIFF       0.0873f  // pre arm gyro check will fail if primary and backup gyro vectors differ by 0.0873 rad/sec (=5deg/sec)
#endif

//////////////////////////////////////////////////////////////////////////////
//  EKF Failsafe
#ifndef FS_EKF_ACTION_DEFAULT
 # define FS_EKF_ACTION_DEFAULT         FS_EKF_ACTION_LAND  // EKF failsafe triggers land by default
#endif
#ifndef FS_EKF_THRESHOLD_DEFAULT
 # define FS_EKF_THRESHOLD_DEFAULT      0.8f    // EKF failsafe's default compass and velocity variance threshold above which the EKF failsafe will be triggered
#endif

#ifndef EKF_ORIGIN_MAX_DIST_M
 # define EKF_ORIGIN_MAX_DIST_M         50000   // EKF origin and waypoints (including home) must be within 50km
#endif

//////////////////////////////////////////////////////////////////////////////
//  MAGNETOMETER
#ifndef MAGNETOMETER
 # define MAGNETOMETER                   ENABLED
#endif

// expected magnetic field strength.  pre-arm checks will fail if 50% higher or lower than this value
#ifndef COMPASS_MAGFIELD_EXPECTED
 #define COMPASS_MAGFIELD_EXPECTED      530        // pre arm will fail if mag field > 874 or < 185
#endif

// max compass offset length (i.e. sqrt(offs_x^2+offs_y^2+offs_Z^2))
#ifndef CONFIG_ARCH_BOARD_PX4FMU_V1
 #ifndef COMPASS_OFFSETS_MAX
  # define COMPASS_OFFSETS_MAX          600         // PX4 onboard compass has high offsets
 #endif
#else   // SITL, FLYMAPLE, etc
 #ifndef COMPASS_OFFSETS_MAX
  # define COMPASS_OFFSETS_MAX          500
 #endif
#endif

//////////////////////////////////////////////////////////////////////////////
//  OPTICAL_FLOW
#ifndef OPTFLOW
 # define OPTFLOW       ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
//  Auto Tuning
#ifndef AUTOTUNE_ENABLED
 # define AUTOTUNE_ENABLED  ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
//  Crop Sprayer
#ifndef SPRAYER
 # define SPRAYER  DISABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// Precision Landing with companion computer or IRLock sensor
#ifndef PRECISION_LANDING
 # define PRECISION_LANDING ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
//	EPM cargo gripper
#ifndef EPM_ENABLED
 # define EPM_ENABLED ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// Parachute release
#ifndef PARACHUTE
 # define PARACHUTE ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// ADSB support
#ifndef ADSB_ENABLED
# define ADSB_ENABLED ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// Nav-Guided - allows external nav computer to control vehicle
#ifndef NAV_GUIDED
 # define NAV_GUIDED    ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// RADIO CONFIGURATION
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// FLIGHT_MODE
//

#ifndef FLIGHT_MODE_1
 # define FLIGHT_MODE_1                  STABILIZE
#endif
#ifndef FLIGHT_MODE_2
 # define FLIGHT_MODE_2                  STABILIZE
#endif
#ifndef FLIGHT_MODE_3
 # define FLIGHT_MODE_3                  STABILIZE
#endif
#ifndef FLIGHT_MODE_4
 # define FLIGHT_MODE_4                  STABILIZE
#endif
#ifndef FLIGHT_MODE_5
 # define FLIGHT_MODE_5                  STABILIZE
#endif
#ifndef FLIGHT_MODE_6
 # define FLIGHT_MODE_6                  STABILIZE
#endif


//////////////////////////////////////////////////////////////////////////////
// Throttle Failsafe
//
#ifndef FS_THR_VALUE_DEFAULT
 # define FS_THR_VALUE_DEFAULT             975
#endif

//////////////////////////////////////////////////////////////////////////////
// Takeoff
//
#ifndef PILOT_TKOFF_ALT_DEFAULT
 # define PILOT_TKOFF_ALT_DEFAULT           0     // default final alt above home for pilot initiated takeoff
#endif


//////////////////////////////////////////////////////////////////////////////
// Landing
//
#ifndef LAND_SPEED
 # define LAND_SPEED    50          // the descent speed for the final stage of landing in cm/s
#endif
#ifndef LAND_START_ALT
 # define LAND_START_ALT 1000         // altitude in cm where land controller switches to slow rate of descent
#endif
#ifndef LAND_REQUIRE_MIN_THROTTLE_TO_DISARM
 # define LAND_REQUIRE_MIN_THROTTLE_TO_DISARM DISABLED  // we do not require pilot to reduce throttle to minimum before vehicle will disarm in AUTO, LAND or RTL
#endif
#ifndef LAND_REPOSITION_DEFAULT
 # define LAND_REPOSITION_DEFAULT   1   // by default the pilot can override roll/pitch during landing
#endif
#ifndef LAND_WITH_DELAY_MS
 # define LAND_WITH_DELAY_MS        4000    // default delay (in milliseconds) when a land-with-delay is triggered during a failsafe event
#endif
#ifndef LAND_CANCEL_TRIGGER_THR
 # define LAND_CANCEL_TRIGGER_THR   700     // land is cancelled by input throttle above 700
#endif

//////////////////////////////////////////////////////////////////////////////
// Landing Detector
//
#ifndef LAND_DETECTOR_TRIGGER_SEC
 # define LAND_DETECTOR_TRIGGER_SEC         1.0f    // number of seconds to detect a landing
#endif
#ifndef LAND_DETECTOR_MAYBE_TRIGGER_SEC
 # define LAND_DETECTOR_MAYBE_TRIGGER_SEC   0.2f    // number of seconds that means we might be landed (used to reset horizontal position targets to prevent tipping over)
#endif
#ifndef LAND_DETECTOR_ACCEL_LPF_CUTOFF
# define LAND_DETECTOR_ACCEL_LPF_CUTOFF     1.0f    // frequency cutoff of land detector accelerometer filter
#endif
#ifndef LAND_DETECTOR_ACCEL_MAX
# define LAND_DETECTOR_ACCEL_MAX            1.0f    // vehicle acceleration must be under 1m/s/s
#endif

//////////////////////////////////////////////////////////////////////////////
// CAMERA TRIGGER AND CONTROL
//
#ifndef CAMERA
 # define CAMERA        ENABLED
#endif

//////////////////////////////////////////////////////////////////////////////
// MOUNT (ANTENNA OR CAMERA)
//
#ifndef MOUNT
 # define MOUNT         ENABLED
#endif


//////////////////////////////////////////////////////////////////////////////
// Flight mode definitions
//

// Acro Mode
#ifndef ACRO_RP_P
 # define ACRO_RP_P                 4.5f
#endif

#ifndef ACRO_YAW_P
 # define ACRO_YAW_P                4.5f
#endif

#ifndef ACRO_LEVEL_MAX_ANGLE
 # define ACRO_LEVEL_MAX_ANGLE      3000
#endif

#ifndef ACRO_BALANCE_ROLL
 #define ACRO_BALANCE_ROLL          1.0f
#endif

#ifndef ACRO_BALANCE_PITCH
 #define ACRO_BALANCE_PITCH         1.0f
#endif

#ifndef ACRO_EXPO_DEFAULT
 #define ACRO_EXPO_DEFAULT          0.3f
#endif

// RTL Mode
#ifndef RTL_ALT_FINAL
 # define RTL_ALT_FINAL             0       // the altitude the vehicle will move to as the final stage of Returning to Launch.  Set to zero to land.
#endif

#ifndef RTL_ALT
 # define RTL_ALT 				    1500    // default alt to return to home in cm, 0 = Maintain current altitude
#endif

#ifndef RTL_ALT_MIN
 # define RTL_ALT_MIN               200     // min height above ground for RTL (i.e 2m)
#endif

#ifndef RTL_CLIMB_MIN_DEFAULT
 # define RTL_CLIMB_MIN_DEFAULT     0       // vehicle will always climb this many cm as first stage of RTL
#endif

#ifndef RTL_ABS_MIN_CLIMB
 # define RTL_ABS_MIN_CLIMB         250     // absolute minimum initial climb
#endif

#ifndef RTL_CONE_SLOPE
 # define RTL_CONE_SLOPE            3.0f    // slope of RTL cone (height / distance). 0 = No cone
#endif

#ifndef RTL_MIN_CONE_SLOPE
 # define RTL_MIN_CONE_SLOPE        0.5f    // minimum slope of cone
#endif

#ifndef RTL_LOITER_TIME
 # define RTL_LOITER_TIME           5000    // Time (in milliseconds) to loiter above home before begining final descent
#endif

// AUTO Mode
#ifndef WP_YAW_BEHAVIOR_DEFAULT
 # define WP_YAW_BEHAVIOR_DEFAULT   WP_YAW_BEHAVIOR_LOOK_AT_NEXT_WP_EXCEPT_RTL
#endif

#ifndef AUTO_YAW_SLEW_RATE
 # define AUTO_YAW_SLEW_RATE    60              // degrees/sec
#endif

#ifndef YAW_LOOK_AHEAD_MIN_SPEED
 # define YAW_LOOK_AHEAD_MIN_SPEED  100             // minimum ground speed in cm/s required before copter is aimed at ground course
#endif

// Super Simple mode
#ifndef SUPER_SIMPLE_RADIUS
 # define SUPER_SIMPLE_RADIUS       1000
#endif

//////////////////////////////////////////////////////////////////////////////
// Stabilize Rate Control
//
#ifndef ROLL_PITCH_INPUT_MAX
 # define ROLL_PITCH_INPUT_MAX      4500            // roll, pitch input range
#endif
#ifndef DEFAULT_ANGLE_MAX
 # define DEFAULT_ANGLE_MAX         4500            // ANGLE_MAX parameters default value
#endif
#ifndef ANGLE_RATE_MAX
 # define ANGLE_RATE_MAX            18000           // default maximum rotation rate in roll/pitch axis requested by angle controller used in stabilize, loiter, rtl, auto flight modes
#endif

//////////////////////////////////////////////////////////////////////////////
// Loiter position control gains
//
#ifndef POS_XY_P
 # define POS_XY_P             	1.0f
#endif

//////////////////////////////////////////////////////////////////////////////
// Stop mode defaults
//
#ifndef BRAKE_MODE_SPEED_Z
 # define BRAKE_MODE_SPEED_Z     250 // z-axis speed in cm/s in Brake Mode
#endif
#ifndef BRAKE_MODE_DECEL_RATE
 # define BRAKE_MODE_DECEL_RATE  750 // acceleration rate in cm/s/s in Brake Mode
#endif

//////////////////////////////////////////////////////////////////////////////
// Velocity (horizontal) gains
//
#ifndef VEL_XY_P
 # define VEL_XY_P              1.0f
#endif
#ifndef VEL_XY_I
 # define VEL_XY_I              0.5f
#endif
#ifndef VEL_XY_IMAX
 # define VEL_XY_IMAX           1000
#endif
#ifndef VEL_XY_FILT_HZ
 # define VEL_XY_FILT_HZ        5.0f
#endif

//////////////////////////////////////////////////////////////////////////////
// PosHold parameter defaults
//
#ifndef POSHOLD_ENABLED
 # define POSHOLD_ENABLED               ENABLED // PosHold flight mode enabled by default
#endif
#ifndef POSHOLD_BRAKE_RATE_DEFAULT
 # define POSHOLD_BRAKE_RATE_DEFAULT    8       // default POSHOLD_BRAKE_RATE param value.  Rotation rate during braking in deg/sec
#endif
#ifndef POSHOLD_BRAKE_ANGLE_DEFAULT
 # define POSHOLD_BRAKE_ANGLE_DEFAULT   3000    // default POSHOLD_BRAKE_ANGLE param value.  Max lean angle during braking in centi-degrees
#endif

//////////////////////////////////////////////////////////////////////////////
// Throttle control gains
//
#ifndef THR_MID_DEFAULT
 # define THR_MID_DEFAULT       500             // Throttle output (0 ~ 1000) when throttle stick is in mid position
#endif

#ifndef THR_MIN_DEFAULT
 # define THR_MIN_DEFAULT       130             // minimum throttle sent to the motors when armed and pilot throttle above zero
#endif
#define THR_MAX                 1000            // maximum throttle input and output sent to the motors

#ifndef THR_DZ_DEFAULT
# define THR_DZ_DEFAULT         100             // the deadzone above and below mid throttle while in althold or loiter
#endif

#ifndef ALT_HOLD_P
 # define ALT_HOLD_P            1.0f
#endif

// Velocity (vertical) control gains
#ifndef VEL_Z_P
 # define VEL_Z_P       5.0f
#endif

// Accel (vertical) control gains
#ifndef ACCEL_Z_P
 # define ACCEL_Z_P     0.50f
#endif
#ifndef ACCEL_Z_I
 # define ACCEL_Z_I     1.00f
#endif
#ifndef ACCEL_Z_D
 # define ACCEL_Z_D     0.0f
#endif
#ifndef ACCEL_Z_IMAX
 # define ACCEL_Z_IMAX  800
#endif
#ifndef ACCEL_Z_FILT_HZ
 # define ACCEL_Z_FILT_HZ   20.0f
#endif

// default maximum vertical velocity and acceleration the pilot may request
#ifndef PILOT_VELZ_MAX
 # define PILOT_VELZ_MAX    250     // maximum vertical velocity in cm/s
#endif
#ifndef PILOT_ACCEL_Z_DEFAULT
 # define PILOT_ACCEL_Z_DEFAULT 250 // vertical acceleration in cm/s/s while altitude is under pilot control
#endif

// max distance in cm above or below current location that will be used for the alt target when transitioning to alt-hold mode
#ifndef ALT_HOLD_INIT_MAX_OVERSHOOT
 # define ALT_HOLD_INIT_MAX_OVERSHOOT 200
#endif
// the acceleration used to define the distance-velocity curve
#ifndef ALT_HOLD_ACCEL_MAX
 # define ALT_HOLD_ACCEL_MAX 250    // if you change this you must also update the duplicate declaration in AC_WPNav.h
#endif

#ifndef AUTO_DISARMING_DELAY
# define AUTO_DISARMING_DELAY  10
#endif

//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//
#ifndef LOGGING_ENABLED
 # define LOGGING_ENABLED                ENABLED
#endif

// Default logging bitmask
#ifndef DEFAULT_LOG_BITMASK
 # define DEFAULT_LOG_BITMASK \
    MASK_LOG_ATTITUDE_MED | \
    MASK_LOG_GPS | \
    MASK_LOG_PM | \
    MASK_LOG_CTUN | \
    MASK_LOG_NTUN | \
    MASK_LOG_RCIN | \
    MASK_LOG_IMU | \
    MASK_LOG_CMD | \
    MASK_LOG_CURRENT | \
    MASK_LOG_RCOUT | \
    MASK_LOG_OPTFLOW | \
    MASK_LOG_COMPASS | \
    MASK_LOG_CAMERA | \
    MASK_LOG_MOTBATT
#endif

//////////////////////////////////////////////////////////////////////////////
// Fence, Rally and Terrain defaults
//

// Enable/disable Fence
#ifndef AC_FENCE
 #define AC_FENCE ENABLED
#endif

#ifndef AC_RALLY
 #define AC_RALLY   ENABLED
#endif

#ifndef AC_TERRAIN
 #define AC_TERRAIN ENABLED
 #if !AC_RALLY
  #error Terrain relies on Rally which is disabled
 #endif
#endif

//////////////////////////////////////////////////////////////////////////////
// Developer Items
//

// use this to completely disable the CLI
#ifndef CLI_ENABLED
  #  define CLI_ENABLED           ENABLED
#endif

//use this to completely disable FRSKY TELEM
#ifndef FRSKY_TELEM_ENABLED
  #  define FRSKY_TELEM_ENABLED          ENABLED
#endif

/*
  build a firmware version string.
  GIT_VERSION comes from Makefile builds
*/
#ifndef GIT_VERSION
#define FIRMWARE_STRING THISFIRMWARE
#else
#define FIRMWARE_STRING THISFIRMWARE " (" GIT_VERSION ")"
#endif
