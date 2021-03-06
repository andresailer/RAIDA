// -*- C++ -*-
#ifndef AIDA_NotYetImplementedException_H
#define AIDA_NotYetImplementedException_H 1

#include <exception>
#include <iostream>
#include <string>

/**
 * Object used to handle exceptions originating from not yet available 
 * functionality.
 * @author T. Kraemer, DESY
 * @version $Id: NotYetImplementedException.h,v 1.2 2006-12-04 17:24:06 tkraemer Exp $
 */

using namespace std;

namespace AIDA {

  class NotYetImplementedException : public std::exception {

  public:

    NotYetImplementedException() {}

    NotYetImplementedException(const string& what_arg);

    NotYetImplementedException(const string& what_function,
			       const string& what_class);

    virtual ~NotYetImplementedException() throw() {}

    virtual const char* what () const throw() 
    { return _what.c_str (); }

  private:

    string _what;

  }; // class
} // namespace AIDA
#endif /* ifndef AIDA_NotYetImplementedException_H */
