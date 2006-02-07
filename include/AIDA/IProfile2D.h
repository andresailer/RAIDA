// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef AIDA_IPROFILE2D_H
#define AIDA_IPROFILE2D_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt 

#include "AIDA/IProfile.h"

namespace AIDA {

class IAxis;

/**
 * User level interface to a 2-dimensional profile histogram
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class IProfile2D : virtual public IProfile {

public: 
    /// Destructor.
    virtual ~IProfile2D() { /* nop */; }

    /**
     * Fill the IProfile2D.
     *
     */
    virtual bool fill(double x, double y, double z, double weight = 1) = 0;

    /**
     * The weighted mean along x of a given bin. 
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The mean of the corresponding bin along the x axis.
     *
     */
    virtual double binMeanX(int indexX, int indexY) const = 0;

    /**
     * The weighted mean along y of a given bin. 
     * @param indexX The x bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @param indexY The y bin number (0...N-1) or OVERFLOW or UNDERFLOW.
     * @return       The mean of the corresponding bin along the x axis.
     *
     */
    virtual double binMeanY(int indexX, int indexY) const = 0;

    /**
     * The number of entries (ie the number of times fill was called for this bin).
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    virtual int binEntries(int indexX, int indexY) const = 0;

    /**
     * Equivalent to <tt>projectionX().binEntries(indexX)</tt>.
     *
     */
    virtual int binEntriesX(int indexX) const = 0;

    /**
     * Equivalent to <tt>projectionY().binEntries(indexY)</tt>.
     *
     */
    virtual int binEntriesY(int indexY) const = 0;

    /**
     * Total height of the corresponding bin (ie the sum of the weights in this bin).
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    virtual double binHeight(int indexX, int indexY) const = 0;

    /**
     * Equivalent to <tt>projectionX().binHeight(indexX)</tt>.
     *
     */
    virtual double binHeightX(int indexX) const = 0;

    /**
     * Equivalent to <tt>projectionY().binHeight(indexY)</tt>.
     *
     */
    virtual double binHeightY(int indexY) const = 0;

    /**
     * The error on this bin.
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    virtual double binError(int indexX, int indexY) const = 0;

    /**
     * The spread (RMS) of this bin.
     * @param indexX the x bin number (0...Nx-1) or OVERFLOW or UNDERFLOW.
     * @param indexY the y bin number (0...Ny-1) or OVERFLOW or UNDERFLOW.
     *
     */
    virtual double binRms(int indexX, int indexY) const = 0;

    /**
     * Returns the mean of the profile, as calculated on filling-time projected on the X axis.
     *
     */
    virtual double meanX() const = 0;

    /**
     * Returns the mean of the profile, as calculated on filling-time projected on the Y axis.
     *
     */
    virtual double meanY() const = 0;

    /**
     * Returns the rms of the profile as calculated on filling-time projected on the X axis.
     *
     */
    virtual double rmsX() const = 0;

    /**
     * Returns the rms of the profile as calculated on filling-time projected on the Y axis.
     *
     */
    virtual double rmsY() const = 0;

    /**
     * Return the X axis.
     *
     */
  /// virtual const IAxis & xAxis() const = 0;

    /**
     * Return the Y axis.
     *
     */
  /// virtual const IAxis & yAxis() const = 0;

    /**
     * Convenience method, equivalent to <tt>xAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     *
     */
    virtual int coordToIndexX(double coordX) const = 0;

    /**
     * Convenience method, equivalent to <tt>yAxis().coordToIndex(coord)</tt>.
     * @see IAxis#coordToIndex(double)
     *
     */
    virtual int coordToIndexY(double coordY) const = 0;

    /**
     * Modifies this profile by adding the contents of profile to it.
     *
     * @param profile The IProfile2D to be added to this IProfile2D
     * @return false if the profile binnings are incompatible
     *
     */
  /// virtual bool add(const IProfile2D & h) = 0;
}; // class
} // namespace AIDA
#endif /* ifndef AIDA_IPROFILE2D_H */