// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   RawDataQcTask.h
/// \author Marek Bombara
/// \author Lucia Anna Tarasovicova
///

#ifndef QC_MODULE_CTP_CTPRAWDATAQCTASK_H
#define QC_MODULE_CTP_CTPRAWDATAQCTASK_H

#include "QualityControl/TaskInterface.h"
#include "CTPReconstruction/RawDataDecoder.h"

class TH1F;

using namespace o2::quality_control::core;

namespace o2::quality_control_modules::ctp
{

/// \brief Task for reading the CTP inputs
class CTPRawDataReaderTask final : public TaskInterface
{
 public:
  /// \brief Constructor
  CTPRawDataReaderTask() = default;
  /// Destructor
  ~CTPRawDataReaderTask() override;

  // Definition of the methods for the template method pattern
  void initialize(o2::framework::InitContext& ctx) override;
  void startOfActivity(const Activity& activity) override;
  void startOfCycle() override;
  void monitorData(o2::framework::ProcessingContext& ctx) override;
  void endOfCycle() override;
  void endOfActivity(const Activity& activity) override;
  void reset() override;

 private:
  o2::ctp::RawDataDecoder mDecoder;
  TH1F* mHistoInputs = nullptr;
  TH1F* mHistoClasses = nullptr;
  TH1F* mHistoInputRatios = nullptr;
  TH1F* mHistoClassRatios = nullptr;
  TH1F* mHistoMTVXBC = nullptr;
};

} // namespace o2::quality_control_modules::ctp

#endif // QC_MODULE_CTP_CTPRAWDATAQCTASK_H
