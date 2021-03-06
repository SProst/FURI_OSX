#pragma once

#include "Phidget.h"
#include <string>

namespace phidgets {
class Spatial : 
	public Phidget
{
public:
	Spatial(void);
    int getAcceleration(int axis);
    int getDataRate(void);
    void printData(void);
	virtual ~Spatial(void);

protected: 
	CPhidgetSpatialHandle spatial_handle_;
	void zero();
	void setDataRate(int rate);

	virtual void dataHandler(CPhidgetSpatial_SpatialEventDataHandle *data, int count);
private: 
	static int CCONV SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count);
    double arr[3];
};

}
