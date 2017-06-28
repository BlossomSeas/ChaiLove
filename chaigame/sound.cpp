#include <SDL.h>
#include <SDL_mixer.h>

#include <string>

#include "sound.h"

namespace chaigame {
	bool sound::load() {
		int flags = MIX_INIT_OGG | MIX_INIT_MOD;
    Uint16 format;
		int initted = Mix_Init(flags);
		if (initted&flags != flags) {
		    printf("Mix_Init: Failed to init required ogg and mod support!\n");
		    printf("Mix_Init: %s\n", Mix_GetError());
		    return false;
		}
printf("Mix_Init");
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
			printf("Mix_OpenAudio: %s\n", Mix_GetError());
			return false;
		}


printf("Mix_MIX");
	    numtimesopened=Mix_QuerySpec(&frequency, &format, &channels);
	    if(!numtimesopened) {
	    	printf("Mix_QuerySpec: %s\n",Mix_GetError());
	    	return false;
	    }


printf("MIX FORMAT");
    	std::string format_str="Unknown";
    	switch(format) {
    	    case AUDIO_U8: format_str="U8"; break;
    	    case AUDIO_S8: format_str="S8"; break;
    	    case AUDIO_U16LSB: format_str="U16LSB"; break;
    	    case AUDIO_S16LSB: format_str="S16LSB"; break;
    	    case AUDIO_U16MSB: format_str="U16MSB"; break;
    	    case AUDIO_S16MSB: format_str="S16MSB"; break;
    	}
    	printf("opened=%d times  frequency=%dHz  format=%s  channels=%d\n",
            numtimesopened, frequency, format_str.c_str(), channels);

		return true;
	}
	bool sound::unload() {
    	Mix_CloseAudio();
		Mix_Quit();
	}
}
