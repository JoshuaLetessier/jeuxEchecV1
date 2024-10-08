#pragma once
#ifdef _DEBUG
	#define VERSION_LOG
#endif _DEBUG

#ifdef VERSION_DEMO
	#define VERSION_LOG
#endif VERSION_DEMO

#ifdef VERSION_LIGHT
	#define VERSION_LOG
#endif VERSION_LIGHT

#ifdef VERSION_CONSOLE
	#define VERSION_LOG(message)			std::cout << message << std::endl
#else
	#define VERSION_LOG(message)
#endif







#ifdef _DEBUG
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif


