# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.asteroids.Debug:
PostBuild.glfw.Debug: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Debug: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Debug: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/asteroids.app/Contents/MacOS/asteroids
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/asteroids.app/Contents/MacOS/asteroids:\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Debug/libglfw3.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/libglad.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Debug:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/libglad.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Debug/libglfw3.a


PostBuild.asteroids.Release:
PostBuild.glfw.Release: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.Release: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.Release: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/asteroids.app/Contents/MacOS/asteroids
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/asteroids.app/Contents/MacOS/asteroids:\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Release/libglfw3.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/libglad.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.Release:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/libglad.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/libglad.a


PostBuild.glfw.Release:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Release/libglfw3.a


PostBuild.asteroids.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.MinSizeRel: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.MinSizeRel: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids:\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/libglad.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.MinSizeRel:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/libglad.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.asteroids.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glad.RelWithDebInfo: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
PostBuild.glfw.RelWithDebInfo: /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids:\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/libglad.a\
	/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/asteroids.app/Contents/MacOS/asteroids


PostBuild.glad.RelWithDebInfo:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Debug/libglad.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/MinSizeRel/libglad.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/RelWithDebInfo/libglad.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/Release/libglad.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Debug/libglfw3.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/noahhendlish/Desktop/Fall\ 2018/CMPS/Intro\ to\ Computer\ Graphics/project/game\ project/build/glfw-3.2/src/Release/libglfw3.a:
