#ifndef STATE_H_
#define STATE_H_

#include <stdint.h>

#define dataType float

// if error set value and go to end
#define PROCESS_ERROR(x) if (0 != (error = (x))) { goto end; }



//  IMU data in RSC (related system of coordinates)
typedef struct {
    dataType accel[3];
    dataType gyro[3];
    dataType magn[3];

} stateIMU_rsc_t;


//  orientation and position of device in ISC (inertial system of coordinates)
typedef struct {
    //  IMU data
    dataType accel[3];
    dataType gyro[3];
    dataType magn[3];

    //  position
    dataType velocities[3];
    dataType coordinates[3];

    //  orientation
    dataType quaternion[4];

} stateIMU_isc_t;


typedef struct {
    float time;

    dataType gyro_staticShift[3];
    dataType accel_staticShift[3];
    dataType zero_quaternion[4];

    dataType magnASA[3];

} state_system_t;


typedef struct
{
    uint8_t descr_val1;     // 0xFF 0xFE
    uint8_t descr_val2;

    uint32_t number;

    float time;

    dataType accel[3];
    dataType gyro[3];
    dataType magn[3];

    dataType quaternion[4];

    uint32_t crc;

}__attribute__((packed, aligned(1))) state_msg_t;
// to make data alignment 1 byte

extern stateIMU_rsc_t stateIMU_rsc;
extern stateIMU_isc_t stateIMU_isc;
extern stateIMU_isc_t stateIMU_isc_prev;
extern state_system_t state_system;
extern state_system_t  state_system_prev;


void stateMsg_fill(state_msg_t* msg);

void stateMsg_send(state_msg_t* msg);


#endif /* STATE */
