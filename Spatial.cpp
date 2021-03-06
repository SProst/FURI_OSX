#include "Spatial.h"
#include <iostream>

using namespace phidgets; 
using namespace std;

namespace phidgets {

Spatial::Spatial(void):
	Phidget(),
	spatial_handle_(0)
{
	int result;
	CPhidgetSpatial_create(&spatial_handle_);
	Phidget::init((CPhidgetHandle) spatial_handle_);
	Phidget::registerHandlers();
    CPhidgetSpatial_set_OnSpatialData_Handler(spatial_handle_, SpatialDataHandler, this);
	Phidget::open();

	printf("Waiting for spatial to be attached.... \n");
	if((result = waitForAttachment(10000)))
	{
		printf("Problem waiting for attachment \n");
	}
}

void Spatial::zero()
{
	// zero (calibrate) gyro
	CPhidgetSpatial_zeroGyro(spatial_handle_);
}

    int Spatial::getAcceleration(int axis)
    {
        double acceleration;
        CPhidgetSpatial_getAcceleration(spatial_handle_, axis, &acceleration);
        return acceleration;
    }

int CCONV Spatial::SpatialDataHandler(CPhidgetSpatialHandle handle, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	((Spatial*)userptr)->dataHandler(data, count);
	return 0;
}

void Spatial::setDataRate(int rate)
{
	CPhidgetSpatial_setDataRate(spatial_handle_, rate);
}

    int Spatial::getDataRate()
    {
        int milliseconds;
        CPhidgetSpatial_getDataRate(spatial_handle_, &milliseconds);
        return milliseconds;
    }
    
void Spatial::printData()
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    }

void Spatial::dataHandler(CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	// cout << "Number of Data Packets in this event: " << count << endl;

	/*for(int i = 0; i < count; i++)
	{
		cout << "=== Data Set:" << i << "===" << endl;
		cout <<"Acceleration> x: " << data[i]->acceleration[0] << " y: " << data[i]->acceleration[1] << " z: " << data[i]->acceleration[2] << endl;
		cout << "Timestamp> seconds: " << data[i]->timestamp.seconds << "-- microseconds: " << data[i]->timestamp.microseconds << endl;
	}*/
    
    for(int i = 0; i < 3; i++)
    {
        arr[i] = data[0]->acceleration[i];
    }
	
}

Spatial::~Spatial(void)
{
}
}