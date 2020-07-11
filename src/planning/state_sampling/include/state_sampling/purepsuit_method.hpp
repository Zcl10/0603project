//
// Created by yangt on 19-5-8.
//

#ifndef STATE_SAMPLING_PUREPSUIT_METHOD_HPP
#define STATE_SAMPLING_PUREPSUIT_METHOD_HPP

#include "state_sampling/collosion_checker.hpp"
#include <opt_utils/opt_utils.hpp>

namespace hmpl {
// base class for state sampling
# define LFR 2.86
# define MAXLATERALACC                1.2 //最大侧向加速度
# define MAXLATERALACC_LOWERBOUND    0.0 //0.8侧向加速度限制的最小前轮偏角
# define MAXLATERALACC_UPPERERBOUND    25 //10.5侧向加速度限制的最小前轮偏角
# define STEERINGANGLELIMIT 50

class PurepursuitSampling {
 public:
    struct ObserveVariable {
        std::vector<hmpl::State> preview_state_set;
        std::vector<std::vector<hmpl::State>> ref_path_set;
        std::vector<std::vector<hmpl::State>> sampling_path_set;

    };
    PurepursuitSampling(const hmpl::InternalGridMap &in_gm,
                        const hmpl::State &vehicle_state);

    static double purePursuitByDeltay(double deltay, double Ld,
                                      double axis_dis);
    static double stanley(double deltatheta, double deviation,
                          double k, double v);

    void puerpursuitPathGeneration(const std::vector<hmpl::State> &ref_path,
                                   std::vector<hmpl::State> *output);

    void generateCandidatePathSet(const std::vector<std::vector<hmpl::State>> &ref_path_set,
                                  std::vector<std::vector<hmpl::State>> *candidate_path);

    void puerpursuitSampling(const std::vector<hmpl::State> &ref_path,
                             std::vector<hmpl::State> *output);

    const ObserveVariable &getObserveVariable() const {
        return this->observe_;
    }

 private:
    CollisionChecker collision_checker_;
    const hmpl::State &vehicle_state_;

    ObserveVariable observe_;

    const double max_offset_;
    const double offset_interval_;
    const double max_preview_distance_;
};

}
#endif //STATE_SAMPLING_PUREPSUIT_METHOD_HPP
