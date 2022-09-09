/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019 Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FS_CHARM_H
#define FS_CHARM_H

#include "player.h"
#include "enums.h"

class Charm;

class Charms {
	public:
		bool loadFromXml(bool reloading = false);
		bool reload();

		Charm* getCharm(uint8_t id);
		std::map<uint8_t, Charm> charms;

	protected:
		friend class Charm;

};

class Charm
{
	public:
		Charm(uint8_t id) :
				id(id) {}

		uint8_t getId() const {
			return id;
		}
		uint8_t getType() const {
			return type;
		}
		uint16_t getPrice() const {
			return price;
		}
		std::string getName() {
			return name;
		}
		std::string getDescription() {
			return description;
		}

	protected:
		friend class Charms;

	private:
		uint16_t price = 0;
		uint8_t type, id = 0;
		std::string name, description = "";
};

#endif
