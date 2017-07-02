#pragma once


/*
Merkt sich den Stand der gedrückten Tasten an zentraler Stelle.
*/

void mem_key_event(char c, bool down);
bool mem_key_state(char c);
