/*! \file WaspSensorRadiation.h
    \brief Library for managing the Radiation board
    
    Copyright (C) 2012 Libelium Comunicaciones Distribuidas S.L.
    http://www.libelium.com
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.
   
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
  
    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
    Version:		0.1
    Design:			David Gascón
    Implementation:	Marcos Yarza, Javier Siscart

*/

 /*! \def WaspSensorRadiation_h
    \brief The library flag
    
  */

#ifndef WaspSensorRadiation_h
#define WaspSensorRadiation_h

/******************************************************************************
 * Includes
 ******************************************************************************/
#include <inttypes.h>


/******************************************************************************
 * Definitions & Declarations
 ******************************************************************************/

// Threshold values for the led bar
#define TH1 75
#define TH2 150
#define TH3 400
#define TH4 600
#define TH5 900

// Conversion factor - CPM to uSV/h
#define CONV_FACTOR 0.008120




/******************************************************************************
 * Class
 ******************************************************************************/

class WaspSensorRadiation{

	private:

	
	//! Function: Count pulses from sensor
    	/*!
	 */
	void countPulse();

	
	public:

	//! class constructor
  	/*!
	  It does nothing
	  \param void
	  \return void
	 */
	WaspSensorRadiation();

	// Variables

	//! Variable : Stores last measured radiation value in uSv/h
    	/*!
	 */
	float radiationValue;
	
	//! Variable : Stores last measured radiation value in cpm
    	/*!
	 */
	float radiationValueCPM;

	//! Variable : 
    	/*!
	 */
	int ledArray [5];

	//! Variable : stores number of pulses counted
    	/*!
	 */
	long count;

	//! Variable : 
    	/*!
	 */
	long timePrevious;

	//! Variable : 
    	/*!
	 */
	long time;

	//! Variable : 
    	/*!
	 */
	long timePreviousMeassure;

	//! Function : Turns on radiation board
    	/*!
	 */
	void ON();

	//! Function : Turns off radiation board
    	/*!
	 */
	void OFF();

	//! Function : enables interrupts and blinks led bar
    	/*!
	 */
	void init();

	//! Function : Measures actual radiation value during 10 seconds.
    	/*!
	 */
	float getRadiation();

	//! Function : Measures actual radiation value during specified time. Maximum measure time is 60 seconds
    	/*!
	 */
	float getRadiation(long time);
	//! Function : Measures actual radiation value during specified time. Maximum time is 60 seconds
    	/*!
	 */
	float getCPM(long time);

	//! Function : Refresh led bar value
    	/*!
	 */
	void ledBar(float value);
};


extern WaspSensorRadiation SensorRadiation;

#endif
