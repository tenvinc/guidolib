/*
  GUIDO Library
  Copyright (C) 2014 Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#ifndef PianoRollTrajectory__
#define PianoRollTrajectory__

#include "PianoRoll.h"

class PianoRollTrajectory : public PianoRoll
{
public:
			 PianoRollTrajectory(ARMusic *arMusic) :  PianoRoll(arMusic), fCurrentDate(0) {}
			 PianoRollTrajectory(const char *midiFileName) : PianoRoll(midiFileName), fCurrentDate(0) {}
	virtual ~PianoRollTrajectory() {}

private:
    typedef struct {
        float x;
        float y;
        VGColor color;
        bool isRest;
    } EventInfos;

	EventInfos createNoteInfos(float x, float y, VGColor &color) const;
    EventInfos createRestInfos(float x) const;

    /**** Chords ****/
    /* Computes if some rights chords points have several links towards them */
	/*
	bool isTherePointOverlap(int x, int y);
	void sortPoints();
	std::vector<EventInfos> *sortList(std::vector<EventInfos> *listToSort);
	*/
	/****************/

	std::vector<EventInfos> fPreviousEventInfos;
	std::vector<EventInfos> fCurrentEventInfos;

protected:
	void init();

//	void DrawVoice(ARMusicalVoice* v, const DrawParams &drawParams);
//    void DrawNote (int pitch, double date, double dur, const DrawParams &drawParams);
    void DrawLinks(const DrawParams &drawParams) const;
    void DrawFinalEvent(double dur, const DrawParams &drawParams);
    void DrawAllLinksBetweenTwoEvents(const DrawParams &drawParams) const;
    void DrawLinkBetween(PianoRollTrajectory::EventInfos leftEvent, PianoRollTrajectory::EventInfos rightEvent, const DrawParams &drawParams) const;

	void handleRest (double date, const DrawParams &drawParams);

#ifdef MIDIEXPORT
//    void DrawMidiSeq(MidiSeqPtr seq, int tpqn, const DrawParams &drawParams);
#endif

    double fCurrentDate;
};

#endif
