// -*- C++ -*-
#ifndef AIDA_ITUPLEROOT_H
#define AIDA_ITUPLEROOT_H 1

#include <AIDA/ITuple.h>
#include <TTree.h>
#include <string>
#include <vector>
#include <RAIDA/LeafPoint.h>

namespace AIDA {

class IAnnotation;
class ICloud1D;
class ICloud2D;
class ICloud3D;
class IEvaluator;
class IFilter;
class IHistogram1D;
class IHistogram2D;
class IHistogram3D;
class IProfile1D;
class IProfile2D;
class ITupleEntry;

/**
 * User level interface to a Tuple.
 * 
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class ITupleROOT : public ITuple {

public: 
  /// Constructor
  ITupleROOT(const std::string & path,
	     const std::string & title,
	     const std::vector<std::string>  & columnNames,
	     const std::vector<std::string>  & columnType,
	     const std::string & options = "") ;

  ITupleROOT() ;

    /// Destructor.
    virtual ~ITupleROOT() { /* nop */; }

    /**
     * Get the title of this ITuple.
     * @return The ITuple's title.
     *
     */
  virtual std::string title() const ;

    /**
     * Set the title of the ITuple.
     * @param title The new ITuple's title.
     * @return false If title cannot be changed.
     *
     */
  virtual bool setTitle(const std::string & title) ;

    /**
     * Get the IAnnotation corresponding to this ITuple.
     * @return The ITuple's IAnnotation.
     *
     */
  /// virtual IAnnotation & annotation() ;

  /// virtual const IAnnotation & annotation() const ;

    /**
     * Fill a given column with a double.
     * @param column The column's index within the ITuple.
     * @param value  The double.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, double value) ;

    /**
     * Fill a given column with a float.
     * @param column The column's index within the ITuple.
     * @param value  The float.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, float value) ;

    /**
     * Fill a given column with an integer.
     * @param column The column's index within the ITuple.
     * @param value  The integer.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, int value) ;

    /**
     * Fill a given column with a short.
     * @param column The column's index within the ITuple.
     * @param value  The short.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, short value) ;

    /**
     * Fill a given column with a long.
     * @param column The column's index within the ITuple.
     * @param value  The long.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, long value) ;

    /**
     * Fill a given column with a char.
     * @param column The column's index within the ITuple.
     * @param value  The char.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, char value) ;

    /**
     * Fill a given column with a boolean.
     * @param column The column's index within the ITuple.
     * @param value  The boolean.
     * @return false If the column is of the wrong type.
     *
     */
  virtual bool fill(int column, bool value) ;

    /**
     * Fill a given column with a string.
     * @param column The column's index within the ITuple.
     * @param value  The string.
     * @return false If the column is of the wrong type.
     *
     */
  /// virtual bool fill(int column, const std::string & value) ;

    /**
     * Fill a given column with an object.
     * @param column The column's index within the ITuple.
     * @param value  The object.
     * @return false If the column is of the wrong type.
     *
     */
  /// virtual bool fill(int column, const ITupleEntry & value) ;

    /**
     * Fill all the columns at once with doubles.
     * @param values The array of doubles.
     * @return false If any column is not of type double or if
     *               the array has the wrong dimension.
     *
     */
  virtual bool fill(const std::vector<double>  & values) ;

    /**
     * Fill all the columns at once with floats.
     * @param values The array of floats.
     * @return false If any column is not of type float or if
     *               the array has the wrong dimension.
     *
     */
  virtual bool fill(const std::vector<float>  & values) ;

    /**
     * Add the current row to the ITuple. This method should be called after 
     * fill has been called for the columns; unfilled columns will be filled 
     * with their default value.
     * @return false When the ITuple runs out of storage space.
     *
     */
  virtual bool addRow() ;

    /**
     * Clear the current(not yet added) row.
     *
     */
  virtual void resetRow() ;

    /**
     * Reset the ITuple. All the rows are reset.
     * The ITuple is as just created.
     *
     */
  virtual void reset() ;

    /**
     * Get the number of rows currently filled in the ITuple.
     * @return The number of rows. -1 if empty or if it cannot be determined.
     *
     */
  virtual int rows() const ;

    /**
     * Positions the read cursor immediately before the first row.
     *
     */
  virtual void start() ;

    /**
     * Skips a given number of rows.
     * @param rows The number of rows to skip.
     * @return false If rows is less than zero or
     *             if it is not possible to perform the jump.
     *
     */
  virtual bool skip(int rows) ;

    /**
     * Positions the cursor at the next row.
     * @return false if there is no next row.
     *
     */
  virtual bool next() ;

    /**
     * Position the cursor at a give row.
     * @param rowIndex The row where the cursor has to be positioned.
     * @return false If the cursor cannot be positioned
     *                 at the give row.
     *
     */
  virtual bool setRow(int rowIndex) ;
  virtual bool mySetRow(int rowIndex) const ;

    /**
     * Get the index within the ITuple of a given column.
     * @param name The colum's name.
     * @return The corresponding column's index. Note: in C++ -1 may
     *         be returned if the column does not exist.
     */
  virtual int findColumn(const std::string & name) const ;

    /**
     * Get the double stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The double.
     *
     */
  virtual double getDouble(int column) const ;

    /**
     * Get the float stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The float.
     *
     */    
  virtual float getFloat(int column) const ;

    /**
     * Get the integer stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The integer.
     *
     */    
  virtual int getInt(int column) const ;

    /**
     * Get the short stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The short.
     *
     */    
  virtual short getShort(int column) const ;

    /**
     * Get the long stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The long.
     *
     */    
  virtual long getLong(int column) const ;

    /**
     * Get the character stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The character.
     *
     */    
  virtual char getChar(int column) const ;

    /**
     * Get the boolean stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The boolean.
     *
     */    
  virtual bool getBoolean(int column) const ;

    /**
     * Get the string stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The string.
     *
     */    
  /// virtual std::string getString(int column) const ;

    /**
     * Get the object stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The object.
     *
     */    
  /// virtual const ITupleEntry * getObject(int column) const ;

    /**
     * Return method for tuple variables of type ITuple for a given column.
     * This method can be used in order to fill a tuple variable in the master tuple.
     * @param column The column's index.
     * @return       The ITuple representing the structure of this column.
     *
     */
  /// virtual const ITuple * getTuple(int column) const ;

  /// virtual ITuple * getTuple(int column) ;

   /** 
    * Get the number of columns in the ITuple
    * @return The number of columns.
    *
    */
  virtual int columns() const ;

   /** 
    * Get the name of a column from its index.
    * @param column The column's index.
    * @return       The column's name.
    *
    */
  virtual std::string columnName(int column) const ;

   /** 
    * Get the names of all the columns.
    * @return  The column names.
    *
    */
  virtual std::vector<std::string>  columnNames() const ;

   /** 
    * Get the type of a give column.
    * @param column The column's type.
    * @return       The column's Class.
    *
    */
  virtual std::string columnType(int column) const ;

   /** 
    * Get the types of all the columns.
    * @return  The column Classes.
    *
    */
  virtual std::vector<std::string>  columnTypes() const ;

   /**
    * Get the minimum value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's minimum value. In Java Double.NaN might be returned.
    *
    */
  virtual double columnMin(int column) const ;

   /**
    * Get the maximum value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's maximum value. In Java Double.NaN might be returned.
    *
    */
  virtual double columnMax(int column) const ;

   /**
    * Get the mean value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's mean value. In Java Double.NaN might be returned.
    *
    */
  virtual double columnMean(int column) const ;

   /**
    * Get the RMS of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's RMS. In Java Double.NaN might be returned.
    *
    */
  virtual double columnRms(int column) const ;

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram1D & histogram, IEvaluator & evaluatorX) ;

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(IHistogram1D & histogram, IEvaluator & evaluatorX, IFilter & filter) ;

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(IHistogram1D & histogram, IEvaluator & evaluatorX, IEvaluator & weight) ;

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(IHistogram1D & histogram, IEvaluator & evaluatorX, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY) ;

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) ;

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) ;

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) ;

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) ;

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) ;

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud1D & cloud, IEvaluator & evaluatorX) ;

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(ICloud1D & cloud, IEvaluator & evaluatorX, IFilter & filter) ;

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(ICloud1D & cloud, IEvaluator & evaluatorX, IEvaluator & weight) ;

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */    
  virtual bool project(ICloud1D & cloud, IEvaluator & evaluatorX, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY) ;

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) ;

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) ;

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) ;

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) ;

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) ;

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY) ;

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) ;

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) ;

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) ;

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) ;

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) ;

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) ;

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis. 
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis. 
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
  virtual bool project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) ;

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
  /// virtual void * cast(const std::string & className) const ;

protected:

  //  std::vector<std::string>  _columnType;
  //  std::vector<std::string>  _columnNames;
  TTree *_theTree;
  std::vector<LeafPoint> _pointVec;
  mutable std::vector<LeafPoint> _readPointVec;
  mutable int _readCursor;
}; // class
} // namespace AIDA
#endif /* ifndef AIDA_ITUPLEROOT_H */