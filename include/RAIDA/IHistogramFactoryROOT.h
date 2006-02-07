// -*- C++ -*-
#ifndef AIDA_IHISTOGRAMFACTORYROOT_H
#define AIDA_IHISTOGRAMFACTORYROOT_H 1

#include <AIDA/IHistogramFactory.h>
#include <AIDA/ITree.h>
#include <AIDA/IHistogram1D.h>
#include <AIDA/IHistogram2D.h>
#include <string>
#include <vector>

namespace AIDA {

  class IBaseHistogram;
  class ICloud1D;
  class ICloud2D;
  class ICloud3D;
  class IHistogram1D;
  class IHistogram2D;
  class IHistogram3D;
  class IProfile1D;
  class IProfile2D;

/**
 * User level interface for factory classes of Histograms (binned, unbinned, and profile)
 * The created objects are assumed to be managed by the tree which is associated to the factory.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */
 
class IHistogramFactoryROOT : public IHistogramFactory {

public: 
    /// Destructor.
    virtual ~IHistogramFactoryROOT() { /* nop */; }

  IHistogramFactoryROOT(ITree & tree);
  IHistogramFactoryROOT() {}

    /**
     * Destroy an IBaseHistogram ogject.
     * @param hist The IBaseHistogram to be destroyed.
     * @return false If the histogram cannot be destroyed.
     *
     */
  /// virtual bool destroy(IBaseHistogram * hist) ;

    /**
     * Create a ICloud1D, an unbinned 1-dimensional histogram.
     * @param path    The path of the created ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param title   The title of the ICloud1D.
     * @param nMax    The maximum number of entries after which the ICloud1D
     *                will convert to an IHistogram1D. The default nMax = -1 means no autoconversion.
     * @param options The options for the ICloud1D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram1D.
     * @return        The newly created ICloud1D.
     *
     */
   virtual ICloud1D * createCloud1D(const std::string & path, 
                                    const std::string & title, 
                                    int nMax = -1, 
                                    const std::string & options = "") ;

    /**
     * Create a ICloud1D, an unbinned 1-dimensional histogram.
     * @param pathAndTitle The path of the created ICloud. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @return             The newly created ICloud1D.
     *
     */
  /// virtual ICloud1D * createCloud1D(const std::string & pathAndTitle) ;

    /**
     * Create a copy of an ICloud1D.
     * @param path    The path of the resulting ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param cloud   The ICloud1D to be copied.
     * @return        The copy of the ICloud1D.
     *
     */
  /// virtual ICloud1D * createCopy(const std::string & path, const ICloud1D & cloud) ;

    /**
     * Create a ICloud2D, an unbinned 2-dimensional histogram.
     * @param path    The path of the created ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param title   The title of the ICloud2D.
     * @param nMax    The maximum number of entries after which the ICloud2D
     *                will convert to an IHistogram2D. The default nMax = -1 means no autoconversion. 
     * @param options The options for the ICloud2D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram2D.
     * @return        The newly created ICloud2D.
     *
     */
  virtual ICloud2D * createCloud2D(const std::string & path, 
                                   const std::string & title, 
                                   int nMax = -1, 
                                   const std::string & options = "") ;

    /**
     * Create a ICloud2D, an unbinned 2-dimensional histogram.
     * @param pathAndTitle The path of the created created ICloud. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @return             The newly created ICloud2D.
     *
     */
  /// virtual ICloud2D * createCloud2D(const std::string & pathAndTitle) ;

    /**
     * Create a copy of an ICloud2D.
     * @param path    The path of the resulting ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param cloud   The ICloud2D to be copied.
     * @return        The copy of the ICloud2D.
     *
     */
  /// virtual ICloud2D * createCopy(const std::string & path, const ICloud2D & cloud) ;

    /**
     * Create a ICloud3D, an unbinned 3-dimensional histogram.
     * @param path    The path of the created ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param title   The title of the ICloud3D.
     * @param nMax    The maximum number of entries after which the ICloud3D
     *                will convert to an IHistogram3D. The default nMax = -1 means no autoconversion 
     * @param options The options for the ICloud3D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram3D.
     * @return        The newly created ICloud3D.
     *
     */
  virtual ICloud3D * createCloud3D(const std::string & path, 
				   const std::string & title, 
				   int nMax = -1, 
				   const std::string & options = "") ;

    /**
     * Create a ICloud3D, an unbinned 3-dimensional histogram.
     * @param pathAndTitle The path of the created created ICloud. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @return             The newly created ICloud3D.
     *
     */
  /// virtual ICloud3D * createCloud3D(const std::string & pathAndTitle) ;

    /**
     * Create a copy of an ICloud3D.
     * @param path    The path of the resulting ICloud. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param cloud   The ICloud3D to be copied.
     * @return        The copy of the ICloud3D.
     *
     */
  /// virtual ICloud3D * createCopy(const std::string & path, const ICloud3D & cloud) ;

    /**
     * Create a IHistogram1D.
     * @param path      The path of the created IHistogram. The path can either be a relative or full path.
     *                  ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                  All the directories in the path must exist. The characther `/` cannot be used
     *                  in names; it is only used to delimit directories within paths.
     * @param title     The title of the IHistogram1D.
     * @param nBins     The number of bins of the x axis.
     * @param lowerEdge The lower edge of the x axis.
     * @param upperEdge The upper edge of the x axis.
     * @param options   The options for the IHistogram1D. The default is "".
     *                  "type=efficiency" for an efficiency IHistogram1D.
     * @return          The newly created IHistogram1D.
     *
     */
  virtual IHistogram1D * createHistogram1D(const std::string & path, 
                                           const std::string & title, 
                                           int nBins, 
                                           double lowerEdge, 
                                           double upperEdge, 
                                           const std::string & options = "") ;

    /**
     * Create a IHistogram1D.
     * @param pathAndTitle The path of the created created IHistogram. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @return             The newly created IHistogram1D.
     *
     */
  virtual IHistogram1D * createHistogram1D(const std::string & pathAndTitle, 
                                           int nBins, 
                                           double lowerEdge, 
                                           double upperEdge) ;

    /**
     * Create a IHistogram1D.
     * @param path      The path of the created IHistogram. The path can either be a relative or full path.
     *                  ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                  All the directories in the path must exist. The characther `/` cannot be used
     *                  in names; it is only used to delimit directories within paths.
     * @param title     The title of the IHistogram1D.
     * @param binEdges  The array of the bin edges for the x axis.
     * @param options   The options for the IHistogram1D. The default is "".
     *                  "type=efficiency" for an efficiency IHistogram1D.
     * @return          The newly created IHistogram1D.
     *
     */
  /// virtual IHistogram1D * createHistogram1D(const std::string & path, const std::string & title, const std::vector<double>  & binEdges, const std::string & options = "") ;

    /**
     * Create a copy of an IHistogram1D.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram1D to be copied.
     * @return     The copy of the IHistogram1D.
     *
     */
  /// virtual IHistogram1D * createCopy(const std::string & path, const IHistogram1D & hist) ;

    /**
     * Create a IHistogram2D.
     * @param path       The path of the created IHistogram. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IHistogram2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param options    The options for the IHistogram2D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram2D.
     * @return           The newly created IHistogram2D.
     *
     */
  virtual IHistogram2D * createHistogram2D(const std::string & path, 
                                           const std::string & title, 
                                           int nBinsX, 
                                           double lowerEdgeX, 
                                           double upperEdgeX, 
                                           int nBinsY, 
                                           double lowerEdgeY, 
                                           double upperEdgeY, 
                                           const std::string & options = "") ;

    /**
     * Create a IHistogram2D.
     * @param pathAndTitle The path of the created created IHistogram. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @return             The newly created IHistogram2D.
     *
     */
  /// virtual IHistogram2D * createHistogram2D(const std::string & pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) ;

    /**
     * Create a IHistogram2D.
     * @param path       The path of the created IHistogram. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IHistogram2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param options    The options for the IHistogram2D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram2D.
     * @return           The newly created IHistogram2D.
     *
     */
  /// virtual IHistogram2D * createHistogram2D(const std::string & path, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options = "") ;

    /**
     * Create a copy of an IHistogram2D.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram2D to be copied.
     * @return     The copy of the IHistogram2D.
     *
     */
  ///virtual IHistogram2D * createCopy(const std::string & copy, const IHistogram2D & hist) ;

    /**
     * Create a IHistogram3D.
     * @param path       The path of the created IHistogram. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IHistogram3D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param nBinsZ     The number of bins of the z axis.
     * @param lowerEdgeZ The lower edge of the z axis.
     * @param upperEdgeZ The upper edge of the z axis.
     * @param options    The options for the IHistogram3D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram3D.
     * @return           The newly created IHistogram3D.
     *
     */
  virtual IHistogram3D * createHistogram3D(const std::string & path, 
                                           const std::string & title, 
                                           int nBinsX, 
                                           double lowerEdgeX, 
                                           double upperEdgeX, 
                                           int nBinsY, 
                                           double lowerEdgeY, 
                                           double upperEdgeY, 
                                           int nBinsZ, 
                                           double lowerEdgeZ, 
                                           double upperEdgeZ, 
                                           const std::string & options = "") ;

    /**
     * Create a IHistogram3D.
     * @param pathAndTitle The path of the created created IHistogram. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @param nBinsZ       The number of bins of the z axis.
     * @param lowerEdgeZ   The lower edge of the z axis.
     * @param upperEdgeZ   The upper edge of the z axis.
     * @return             The newly created IHistogram3D.
     *
     */
  ///virtual IHistogram3D * createHistogram3D(const std::string & pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) ;

    /**
     * Create a IHistogram3D.
     * @param path       The path of the created IHistogram. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IHistogram3D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param binEdgesZ  The array of the bin edges for the z axis.
     * @param options    The options for the IHistogram3D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram3D.
     * @return           The newly created IHistogram3D.
     *
     */
  /// virtual IHistogram3D * createHistogram3D(const std::string & path, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::vector<double>  & binEdgesZ, const std::string & options = "") ;

    /**
     * Create a copy of an IHistogram3D.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram3D to be copied.
     * @return     The copy of the IHistogram3D.
     *
     */
  /// virtual IHistogram3D * createCopy(const std::string & path, const IHistogram3D & hist) ;

    /**
     * Create a IProfile1D.
     * @param path      The path of the created IProfile. The path can either be a relative or full path.
     *                  ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                  All the directories in the path must exist. The characther `/` cannot be used
     *                  in names; it is only used to delimit directories within paths.
     * @param title     The title of the IProfile1D.
     * @param nBins     The number of bins of the x axis.
     * @param lowerEdge The lower edge of the x axis.
     * @param upperEdge The upper edge of the x axis.
     * @param options   The options for the IProfile1D. The default is "".
     * @return          The newly created IProfile1D.
     *
     */
  virtual IProfile1D * createProfile1D(const std::string & path, 
                                       const std::string & title, 
                                       int nBins, 
                                       double lowerEdge, 
                                       double upperEdge, 
                                       const std::string & options = "") ;

    /**
     * Create a IProfile1D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile1D.
     * @param nBins      The number of bins of the x axis.
     * @param lowerEdge  The lower edge of the x axis.
     * @param upperEdge  The upper edge of the x axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile1D. The default is "".
     * @return           The newly created IProfile1D.
     *
     */
  /// virtual IProfile1D * createProfile1D(const std::string & path, const std::string & title, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue, const std::string & options = "") ;

    /**
     * Create a IProfile1D.
     * @param path      The path of the created IProfile. The path can either be a relative or full path.
     *                  ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                  All the directories in the path must exist. The characther `/` cannot be used
     *                  in names; it is only used to delimit directories within paths.
     * @param title     The title of the IProfile1D.
     * @param binEdges  The array of the bin edges for the x axis.
     * @param options   The options for the IProfile1D. The default is "".
     * @return          The newly created IProfile1D.
     *
     */
  /// virtual IProfile1D * createProfile1D(const std::string & path, const std::string & title, const std::vector<double>  & binEdges, const std::string & options = "") ;

    /**
     * Create a IProfile1D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile1D.
     * @param binEdges   The array of the bin edges for the x axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile1D. The default is "".
     * @return           The newly created IProfile1D.
     *
     */
  /// virtual IProfile1D * createProfile1D(const std::string & path, const std::string & title, const std::vector<double>  & binEdges, double lowerValue, double upperValue, const std::string & options = "") ;

    /**
     * Create a IProfile1D.
     * @param pathAndTitle The path of the created created IProfile. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @return             The newly created IProfile1D.
     *
     */
  /// virtual IProfile1D * createProfile1D(const std::string & pathAndTitle, int nBins, double lowerEdge, double upperEdge) ;

    /**
     * Create a IProfile1D.
     * @param pathAndTitle The path of the created created IProfile. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @param lowerValue   The lower value displayed along the y axis.
     * @param upperValue   The upper value displayed along the y axis.
     * @return             The newly created IProfile1D.
     *
     */
  /// virtual IProfile1D * createProfile1D(const std::string & pathAndTitle, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue) ;

    /**
     * Create a copy of an IProfile1D.
     * @param path    The path of the resulting IProfile. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param profile The IProfile1D to be copied.
     * @return        The copy of the IProfile1D.
     *
     */
  /// virtual IProfile1D * createCopy(const std::string & path, const IProfile1D & profile) ;

    /**
     * Create a IProfile2D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
  virtual IProfile2D * createProfile2D(const std::string & path, 
                                       const std::string & title, 
                                       int nBinsX, 
                                       double lowerEdgeX, 
                                       double upperEdgeX, 
                                       int nBinsY, 
                                       double lowerEdgeY, 
                                       double upperEdgeY, 
                                       const std::string & options = "") ;

    /**
     * Create a IProfile2D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param lowerValue The lower value displayed along the z axis.
     * @param upperValue The upper value displayed along the z axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
  /// virtual IProfile2D * createProfile2D(const std::string & path, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue, const std::string & options = "") ;

    /**
     * Create a IProfile2D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
  /// virtual IProfile2D * createProfile2D(const std::string & path, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options = "") ;

    /**
     * Create a IProfile2D.
     * @param path       The path of the created IProfile. The path can either be a relative or full path.
     *                   ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                   All the directories in the path must exist. The characther `/` cannot be used
     *                   in names; it is only used to delimit directories within paths.
     * @param title      The title of the IProfile2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
  /// virtual IProfile2D * createProfile2D(const std::string & path, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, double lowerValue, double upperValue, const std::string & options = "") ;

    /**
     * Create a IProfile2D.
     * @param pathAndTitle The path of the created created IProfile. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @return             The newly created IProfile2D.
     *
     */
  /// virtual IProfile2D * createProfile2D(const std::string & pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) ;

    /**
     * Create a IProfile2D.
     * @param pathAndTitle The path of the created created IProfile. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @param lowerValue   The lower value displayed along the z axis.
     * @param upperValue   The upper value displayed along the z axis.
     * @return             The newly created IProfile2D.
     *
     */
  /// virtual IProfile2D * createProfile2D(const std::string & pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue) ;

    /**
     * Create a copy of an IProfile2D.
     * @param path    The path of the resulting IProfile. The path can either be a relative or full path.
     *                ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *                All the directories in the path must exist. The characther `/` cannot be used
     *                in names; it is only used to delimit directories within paths.
     * @param profile The IProfile2D to be copied.
     * @return        The copy of the IProfile2D.
     *
     */
  /// virtual IProfile2D * createCopy(const std::string & path, const IProfile2D & profile) ;

    /**
     * Create an IHistogram1D by adding two IHistogram1D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram1D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram1D * add(const std::string & path, const IHistogram1D & hist1, const IHistogram1D & hist2) ;

    /**
     * Create an IHistogram1D by subtracting two IHistogram1D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram1D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram1D * subtract(const std::string & path, const IHistogram1D & hist1, const IHistogram1D & hist2) ;

    /**
     * Create an IHistogram1D by multiplying two IHistogram1D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram1D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram1D * multiply(const std::string & path, const IHistogram1D & hist1, const IHistogram1D & hist2) ;

    /**
     * Create an IHistogram1D by dividing two IHistogram1D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram1D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram1D * divide(const std::string & path, const IHistogram1D & hist1, const IHistogram1D & hist2) ;

    /**
     * Create an IHistogram2D by adding two IHistogram2D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram2D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram2D * add(const std::string & path, const IHistogram2D & hist1, const IHistogram2D & hist2) ;

    /**
     * Create an IHistogram2D by subtracting two IHistogram2D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram2D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram2D * subtract(const std::string & path, const IHistogram2D & hist1, const IHistogram2D & hist2) ;

    /**
     * Create an IHistogram2D by multiplying two IHistogram2D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram2D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram2D * multiply(const std::string & path, const IHistogram2D & hist1, const IHistogram2D & hist2) ;

    /**
     * Create an IHistogram2D by dividing two IHistogram2D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram2D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram2D * divide(const std::string & path, const IHistogram2D & hist1, const IHistogram2D & hist2) ;

    /**
     * Create an IHistogram3D by adding two IHistogram3D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram3D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram3D * add(const std::string & path, const IHistogram3D & hist1, const IHistogram3D & hist2) ;

    /**
     * Create an IHistogram3D by subtracting two IHistogram3D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram3D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram3D * subtract(const std::string & path, const IHistogram3D & hist1, const IHistogram3D & hist2) ;

    /**
     * Create an IHistogram3D by multiplying two IHistogram3D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram3D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram3D * multiply(const std::string & path, const IHistogram3D & hist1, const IHistogram3D & hist2) ;

    /**
     * Create an IHistogram3D by dividing two IHistogram3D.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram3D.
     *              if a directory in the path does not exist, or the path is illegal.
     *
     */
  /// virtual IHistogram3D * divide(const std::string & path, const IHistogram3D & hist1, const IHistogram3D & hist2) ;

    /**
     * Create an IHistogram1D by projecting an IHistogram2D along its x axis.
     * This is equivalent to <tt>sliceX(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram2D to be projected.
     * @return     The resulting projection.
     *
     */
  /// virtual IHistogram1D * projectionX(const std::string & path, const IHistogram2D & hist) ;

    /**
     * Create an IHistogram1D by projecting an IHistogram2D along its y axis.
     * This is equivalent to <tt>sliceY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram2D to be projected.
     * @return     The resulting projection.
     *
     */
  /// virtual IHistogram1D * projectionY(const std::string & path, const IHistogram2D & hist) ;

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the y axis at a given bin.
     * This is equivalent to <tt>sliceX(indexY,indexY)</tt>.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist  The IHistogram2D to be sliced.
     * @param index The index of the bin along the y axis where the IHistogram2D has to be sliced.
     * @return      The resulting slice.
     *
     */
  /// virtual IHistogram1D * sliceX(const std::string & path, const IHistogram2D & hist, int index) ;

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the x axis at a given bin.
     * This is equivalent to <tt>sliceY(indexX,indexX)</tt>.
     * @param path  The path of the resulting IHistogram. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param hist  The IHistogram2D to be sliced.
     * @param index The index of the bin along the x axis where the IHistogram2D has to be sliced.
     * @return      The resulting slice.
     *
     */
  /// virtual IHistogram1D * sliceY(const std::string & path, const IHistogram2D & hist, int index) ;

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the y axis between two bins (inclusive).
     * @param path   The path of the resulting IHistogram. The path can either be a relative or full path.
     *               ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *               All the directories in the path must exist. The characther `/` cannot be used
     *               in names; it is only used to delimit directories within paths.
     * @param hist   The IHistogram2D to be sliced.
     * @param index1 The index of the bin along the y axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the y axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
  /// virtual IHistogram1D * sliceX(const std::string & path, const IHistogram2D & hist, int index1, int index2) ;

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the x axis between two bins (inclusive).
     * @param path   The path of the resulting IHistogram. The path can either be a relative or full path.
     *               ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *               All the directories in the path must exist. The characther `/` cannot be used
     *               in names; it is only used to delimit directories within paths.
     * @param hist   The IHistogram2D to be sliced.
     * @param index1 The index of the bin along the x axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the x axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
  /// virtual IHistogram1D * sliceY(const std::string & path, const IHistogram2D & hist, int index1, int index2) ;

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the x-y plane.
     * This is equivalent to <tt>sliceXY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
  /// virtual IHistogram2D * projectionXY(const std::string & path, const IHistogram3D & hist) ;

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the x-z plane.
     * This is equivalent to <tt>sliceXZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
  /// virtual IHistogram2D * projectionXZ(const std::string & path, const IHistogram3D & hist) ;

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the y-z plane.
     * This is equivalent to <tt>sliceYZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param path The path of the resulting IHistogram. The path can either be a relative or full path.
     *             ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *             All the directories in the path must exist. The characther `/` cannot be used
     *             in names; it is only used to delimit directories within paths.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
  /// virtual IHistogram2D * projectionYZ(const std::string & path, const IHistogram3D & hist) ;

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the Z axis,
     * between "index1" and "index2" (inclusive).
     * The X axis of the IHistogram2D corresponds to the X axis of this IHistogram3D.
     * The Y axis of the IHistogram2D corresponds to the Y axis of this IHistogram3D.
     * @param path   The path of the resulting IHistogram. The path can either be a relative or full path.
     *               ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *               All the directories in the path must exist. The characther `/` cannot be used
     *               in names; it is only used to delimit directories within paths.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the z axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the z axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
  /// virtual IHistogram2D * sliceXY(const std::string & path, const IHistogram3D & hist, int index1, int index2) ;

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the Y axis,
     * between "index1" and "index2" (inclusive).
     * The X axis of the IHistogram2D corresponds to the X axis of this IHistogram3D.
     * The Z axis of the IHistogram2D corresponds to the Z axis of this IHistogram3D.
     * @param path   The path of the resulting IHistogram. The path can either be a relative or full path.
     *               ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *               All the directories in the path must exist. The characther `/` cannot be used
     *               in names; it is only used to delimit directories within paths.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the y axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the y axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
  /// virtual IHistogram2D * sliceXZ(const std::string & path, const IHistogram3D & hist, int index1, int index2) ;

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the X axis,
     * between "index1" and "index2" (inclusive).
     * The Y axis of the IHistogram2D corresponds to the Y axis of this IHistogram3D.
     * The Z axis of the IHistogram2D corresponds to the Z axis of this IHistogram3D.
     * @param path   The path of the resulting IHistogram. The path can either be a relative or full path.
     *               ("/folder1/folder2/dataName" and "../folder/dataName" are valid paths).
     *               All the directories in the path must exist. The characther `/` cannot be used
     *               in names; it is only used to delimit directories within paths.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the x axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the x axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
  /// virtual IHistogram2D * sliceYZ(const std::string & path, const IHistogram3D & hist, int index1, int index2) ;

private:

  ITree* _usedTree; 

}; // class
} // namespace AIDA
#endif /* ifndef AIDA_IHISTOGRAMFACTORYROOT_H */