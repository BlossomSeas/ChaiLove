#ifndef SRC_LOVE_KEYBOARD_H_
#define SRC_LOVE_KEYBOARD_H_

#include <string>
#include <map>

#include "libretro.h"

namespace love {
/**
 * @brief Provides an interface to the user's keyboard.
 */
class keyboard {
	public:
	bool load();

	/**
	 * @brief Checks whether a certain key is down.
	 *
	 * @param key The key to check.
	 *
	 * @return True if the key is down, false if not.
	 */
	bool isDown(const std::string& key);

	/**
	 * @brief Checks whether a certain key is down.
	 *
	 * @param scancode The key scancode to check.
	 *
	 * @return True if the key is down, false if not.
	 */
	bool isDown(int scancode);

	/**
	 * @brief Checks whether a certain key is down.
	 *
	 * @param scancode The key scancode to check.
	 *
	 * @return True if the key is down, false if not.
	 */
	bool isScancodeDown(int scancode);

	bool update();

	/**
	 * @brief Retrieve a scancode from the given key.
	 *
	 * @see love.keyboard.getKeyFromScancode
	 */
	int getScancodeFromKey(const std::string& key);

	/**
	 * @brief Retrieve a key from the given scancode.
	 *
	 * @see love.keyboard.getScancodeFromKey
	 */
	std::string getKeyFromScancode(int scancode);

	std::map<std::string, int> keyToScancode;
	std::string scancodeToKey[RETROK_LAST] = {};
	int16_t keys[RETROK_LAST] = {};

	void eventKeyPressed(int key);
	void eventKeyReleased(int key);
};

}  // namespace love

#endif  // SRC_LOVE_KEYBOARD_H_
