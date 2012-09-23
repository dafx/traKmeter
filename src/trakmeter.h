/* ----------------------------------------------------------------------------

   traKmeter
   =========
   Loudness meter for correctly setting up tracking and mixing levels

   Copyright (c) 2012 Martin Zuther (http://www.mzuther.de/)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Thank you for using free software!

---------------------------------------------------------------------------- */

#ifndef __TRAKMETER_H__
#define __TRAKMETER_H__

class AverageMeter;
class PeakMeter;

#include "juce_library_code/juce_header.h"
#include "average_meter.h"
#include "peak_meter.h"


//==============================================================================
/**
*/
class TraKmeter : public Component
{
public:
    static const int TRAKMETER_LABEL_WIDTH = 36;
    static const int TRAKMETER_SEGMENT_WIDTH = 22;
    static const int TRAKMETER_SEGMENT_HEIGHT = 9;

    TraKmeter(const String& componentName, int PosX, int PosY, int nCrestFactor, int nNumChannels);
    ~TraKmeter();

    void setLevels(MeterBallistics* pMeterBallistics);
    void paint(Graphics& g);
    void resized();
    void visibilityChanged();

private:
    JUCE_LEAK_DETECTOR(TraKmeter);

    int nPosX;
    int nPosY;
    int nHeight;
    int nWidth;

    int nHeightPeakMeter;
    int nHeightAverageMeter;
    int nHeightSeparator;

    int nInputChannels;

    PeakMeter* peak_meter;
    AverageMeter* average_meter;

    void drawMarkers(Graphics& g, String& strMarker, int x, int y, int width, int height);
};


#endif  // __TRAKMETER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
