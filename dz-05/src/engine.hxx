#pragma once
#include <cstddef>
#include <string_view>

constexpr std::string_view event_quit = "quit";
constexpr std::string_view event_pressed = "pressed";
constexpr std::string_view event_reliased = "reliased";
constexpr std::string_view event_motion = "mouse_motion";

struct event
{
  uint16_t key;
  std::string_view event_type;
  int32_t mouse_x;
  int32_t mouse_y;
};

struct uniform
{
  int f0;
  int f1;
};

struct vertex
{
  float x = 0.f;
  float y = 0.f;
  float z = 0.f;
  float r = 0.f;
  float g = 0.f;
  float b = 0.f;
  float a = 0.f;
};

struct triangle
{
  vertex v[3];
};

class engine
{
public:
  virtual ~engine();
  virtual bool init() = 0;
  virtual bool read_input(event& e) = 0;
  virtual void render_triangle(const triangle& t) = 0;
  virtual void set_uniforms(const uniform& un) = 0;
  virtual void swap_buffers() = 0;
  virtual void destroy() = 0;
};

engine*
create_engine();
void
destroy_engine(engine* e);