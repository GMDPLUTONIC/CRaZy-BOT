#include "crazybot.hpp"

using InputType = crazybot::Input::InputType;

// Declare the meta by using a struct
struct ReplayMeta {
  uint64_t seed;
};

crazybot::Replay<ReplayMeta> replay;
// Set tps by directly changing the member
replay.m_tps = 240.0;

// Add inputs to the replay
replay.addInput(400, InputType::Jump, false, true);
replay.addInput(500, InputType::Jump, false, false);

// Change the TPS mid-replay
replay.addTPSInput(1000, 720.0);

// Save the replay
std::ostream file("out.crazy");
replay.write(file);