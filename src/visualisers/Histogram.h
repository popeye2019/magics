/******************************** LICENSE ********************************

 Copyright 2007 European Centre for Medium-Range Weather Forecasts (ECMWF)

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 ******************************** LICENSE ********************************/

/*! \file Histogram.h
    \brief Definition of the Template class Histogram.
    
    Magics Team - ECMWF 2004
    
    Started: Tue 18-May-2004
    
    Changes:
    
*/

#ifndef Histogram_H
#define Histogram_H

#include "magics.h"

#include "Visdef.h"
#include "HistogramAttributes.h"
#include "IntervalMap.h"
#include "HistoVisitor.h"

namespace magics {


class Histogram: 
	public Visdef,
	public HistogramAttributes, 
	public LevelSelectionInterface {

public:
	Histogram();
	virtual ~Histogram();
    
	    void operator()(Data&, BasicGraphicsObjectContainer& ) { ASSERT(false); }
	    void visit(LegendVisitor& legend);
	    // Implements the set method ... 
	    void set(const map<string, string>& map ) { HistogramAttributes::set(map); }
		void set(const XmlNode& node ) { HistogramAttributes::set(node); }
		
		void visit(const IntervalMap<Colour>&, Data&, PointsHandler& data, HistoVisitor& parent);
		
		void prepare(PointsHandler& data);
		void bean(PointsHandler& data);
		IntervalMap<int>& histogram(const IntervalMap<Colour>&, PointsHandler&);

		double mean() { return mean_; }
		double population() { return population_; }

protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream&) const; 
	 int getCount() const { return count_; }
	 int getTolerance() const { return tolerance_; }
	 double getReference() const { return reference_; }
	 double getInterval() const { return interval_; }
	 double getMin() const { return min_; }
	 double getMax() const { return max_; }
	 floatarray getList()  const { return list_; }
     
	  IntervalMap<int> counter_;

	  double mean_;
	  int population_;

private:
    //! Copy constructor - No copy allowed
	Histogram(const Histogram&);
    //! Overloaded << operator to copy - No copy allowed
	Histogram& operator=(const Histogram&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const Histogram& p)
		{ p.print(s); return s; }

};

template<>
class MagTranslator<string, Histogram  > {
public:
	Histogram* operator()(const string& val ) {
		 return SimpleObjectMaker<Histogram  >::create(val);
	}
    
	Histogram* magics(const string& param)
	{
		Histogram* object;
		ParameterManager::update(param, object);
		return object;
	}
};
} // namespace magics

#endif
