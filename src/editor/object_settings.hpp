//  SuperTux
//  Copyright (C) 2015 Hume2 <teratux.mail@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_EDITOR_OBJECT_SETTINGS_HPP
#define HEADER_SUPERTUX_EDITOR_OBJECT_SETTINGS_HPP

#include <vector>
#include <memory>

#include "editor/object_option.hpp"

class Color;
enum class Direction;

class ObjectSettings final
{
public:
  ObjectSettings(const std::string& name);

  const std::string& get_name() const { return m_name; }

  void add_option(std::unique_ptr<ObjectOption> option);

  void add_bool(const std::string& text, bool* value_ptr,
                const std::string& key = {},
                boost::optional<bool> default_value = {},
                unsigned int flags = 0);
  void add_float(const std::string& text, float* value_ptr,
                 const std::string& key = {},
                 boost::optional<float> default_value = {},
                 unsigned int flags = 0);
  void add_int(const std::string& text, int* value_ptr,
               const std::string& key = {},
               boost::optional<int> default_value = {},
               unsigned int flags = 0);
  void add_direction(const std::string& text, Direction* value_ptr,
                     boost::optional<Direction> default_value = {},
                     const std::string& key = {}, unsigned int flags = 0);
  void add_badguy(const std::string& text, std::vector<std::string>* value_ptr,
                  const std::string& key = {}, unsigned int flags = 0);
  void add_color(const std::string& text, Color* value_ptr,
                 const std::string& key = {},
                 boost::optional<Color> default_value = {},
                 unsigned int flags = 0);
  void add_remove();
  void add_script(const std::string& text, std::string* value_ptr,
                  const std::string& key = {}, unsigned int flags = 0);
  void add_text(const std::string& text, std::string* value_ptr,
                const std::string& key = {}, unsigned int flags = 0);
  void add_string_select(const std::string& text, int* value_ptr, const std::vector<std::string>& select,
                         boost::optional<int> default_value = {},
                         const std::string& key = {}, unsigned int flags = 0);
  void add_level(const std::string& text, std::string* value_ptr, const std::string& key = {},
                 unsigned int flags = 0);
  void add_sprite(const std::string& text, std::string* value_ptr, const std::string& key = {},
                  unsigned int flags = 0);
  void add_surface(const std::string& text, std::string* value_ptr, const std::string& key = {},
                   unsigned int flags = 0);
  void add_sound(const std::string& text, std::string* value_ptr, const std::string& key = {},
                 unsigned int flags = 0);
  void add_music(const std::string& text, std::string* value_ptr, const std::string& key = {},
                 unsigned int flags = 0);
  void add_worldmap(const std::string& text, std::string* value_ptr, const std::string& key = {},
                    unsigned int flags = 0);

  const std::vector<std::unique_ptr<ObjectOption> >& get_options() const { return m_options; }

  /** Avoid using this one */
  std::vector<std::unique_ptr<ObjectOption> >& get_options_writable() { return m_options; }

private:
  void add_file(const std::string& text, std::string* value_ptr, const std::string& key = {},
                const std::vector<std::string>& filter = {}, unsigned int flags = 0);

private:
  std::string m_name;
  std::vector<std::unique_ptr<ObjectOption> > m_options;
};

#endif

/* EOF */
