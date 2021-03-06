#ifndef ARStaccato_H
#define ARStaccato_H

/*
  GUIDO Library
  Copyright (C) 2002  Holger Hoos, Juergen Kilian, Kai Renz
  Copyright (C) 2002-2017 Grame

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr

*/

#include "ARArticulation.h"

/*@mkdoc

@group:Articulations

@tagname:\staccato
@tagalias:\stacc <br /> \staccBegin \staccEnd
@tagtype:R
@tagnotation:staccato signs
@tagdesc
@tagend

@params:
@param:type:string:heavy or regular:regular:true
@param:position:string:above or below:*none*:true
@paramdesc
The default staccato position is close to the note head, on the opposite side of the stem.

See the [Articulations](@EXAMPLES/articulations/) example.
@paramend

*/

/** \brief Staccato Tag
*/
class ARStaccato : public ARArticulation
{		
	public:			
		enum		tTypeStacc {REGULAR, HEAVY};

		virtual bool MatchEndTag(const char * s);

				 ARStaccato();
		virtual ~ARStaccato() {};

		virtual void setTagParameters (const TagParameterMap& params);

//		virtual void browse(TimeUnwrap& mapper) const;

		virtual const char*	getParamsStr() const	{ return kARStaccatoParams; };
		virtual const char*	getTagName() const		{ return "ARStaccato"; };
		virtual std::string getGMNName() const		{ return "\\staccato"; };
		virtual unsigned int getSymbol() const;

		tTypeStacc getType() const		{ return fType; };

	private:
		tTypeStacc	fType;
};

#endif
