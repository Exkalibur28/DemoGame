#include "key_memorizer.h"
#include <map>

static std::map<char, bool> keymap;

void mem_key_event(char c, bool down) {
	keymap[c] = down;
}

bool mem_key_state(char c)
{
	if (keymap.find(c) == keymap.end()) {
		keymap[c] = false;
	}
	return keymap[c];
}
