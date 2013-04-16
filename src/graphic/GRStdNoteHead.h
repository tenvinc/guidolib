#ifndef GRStdNoteHead_H
#define GRStdNoteHead_H

/*
  GUIDO Library
  Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
  Copyright (C) 2003 Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#include "GRNoteHead.h"
#include "ARTHead.h"

class GREvent;
class GRChord;

/** \brief Graphical representation of a note head.
*/
class GRStdNoteHead : public GRNoteHead 
{
public:
	friend class GRChord;

	GRStdNoteHead(GREvent * sngnote, const TYPE_DURATION & inDur, GDirection inStemDirection = dirAUTO);
	virtual	 	~GRStdNoteHead();

	virtual NVPoint getNoteHeadPosition() const;
	virtual const NVPoint & getPosition() const;

	// static long getNoteBreite();

	virtual const NVPoint & getReferencePosition() const;
	virtual void OnDraw( VGDevice & hdc ) const;

	virtual void GGSOutput() const;

	virtual void print() const;

	virtual unsigned int getSymbol() const;

	virtual void adjustPositionForChords(ARTHead::HEADSTATE inHeadstate, GDirection inGlobalStemDirection);

	/*	enum HEADTYPES { NOHEAD = kNoneSymbol, 
	WHOLENOTEHEAD = kWholeNoteHeadSymbol, // SCR_WHOLENOTEHEAD,
	HALFNOTEHEAD = kHalfNoteHeadSymbol, // SCR_HALFNOTEHEAD,
	FULLHEAD = kFullHeadSymbol, // SCR_FULLHEAD,
	ERRORHEAD = kErrorHeadSymbol // SCR_ERRORHEAD
	};
	*/

protected:

	virtual unsigned int durationToHeadSymbol( const TYPE_DURATION & inDur ) const;

	NVPoint sRefPosNotehead;

	NVstring mStyle;

	GDirection singleStemDirection;
	GDirection globalStemDirection;

	float halfExtent;
};

#endif


