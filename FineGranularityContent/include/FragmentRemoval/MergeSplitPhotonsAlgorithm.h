/**
 *  @file   PandoraPFANew/FineGranularityContent/include/FragmentRemoval/MergeSplitPhotonsAlgorithm.h
 * 
 *  @brief  Header file for the merge split photons algorithm class.
 * 
 *  $Log: $
 */
#ifndef MERGE_SPLIT_PHOTONS_ALGORITHM_H
#define MERGE_SPLIT_PHOTONS_ALGORITHM_H 1

#include "Pandora/Algorithm.h"

/**
 *  @brief  MergeSplitPhotonsAlgorithm class
 */
class MergeSplitPhotonsAlgorithm : public pandora::Algorithm
{
public:
    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
        pandora::Algorithm *CreateAlgorithm() const;
    };

private:
    /**
     *  @brief  Get the cluster layer in which the maximum electromagnetic energy has been deposited
     * 
     *  @param  pCluster address of the cluster
     * 
     *  @return The shower max layer
     */
    pandora::PseudoLayer GetShowerMaxLayer(const pandora::Cluster *const pCluster) const;

    pandora::StatusCode Run();
    pandora::StatusCode ReadSettings(const TiXmlHandle xmlHandle);

    // Member variables here
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *MergeSplitPhotonsAlgorithm::Factory::CreateAlgorithm() const
{
    return new MergeSplitPhotonsAlgorithm();
}

#endif // #ifndef MERGE_SPLIT_PHOTONS_ALGORITHM_H
