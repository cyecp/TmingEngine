if(WIN32)
	add_subdirectory(gl3w)
	SET_PROPERTY(TARGET gl3w  PROPERTY FOLDER "ThirdParty")
elseif(IOS)

elseif(APPLE)

	add_subdirectory(gl3w)
	SET_PROPERTY(TARGET gl3w  PROPERTY FOLDER "ThirdParty")
elseif(ANDROID)

elseif(LINUX)

	add_subdirectory(gl3w)
	SET_PROPERTY(TARGET gl3w  PROPERTY FOLDER "ThirdParty")	
endif()


#add_subdirectory(glad)
add_subdirectory(Lua)
add_subdirectory(Box2D)
add_subdirectory(KHR)
add_subdirectory(GLFW)
add_subdirectory(glm)
add_subdirectory(Assimp)
add_subdirectory(ImGui)		#version 1.79 docking
add_subdirectory(Stb_Image)
add_subdirectory(yaml)
add_subdirectory(TextEditor)
add_subdirectory(ImNodes)
add_subdirectory(Angelscript/sdk/angelscript/projects/cmake)
add_subdirectory(tgaimage)
add_subdirectory(SDL2)   #version 2.0.12

#SET_PROPERTY(TARGET glad  PROPERTY FOLDER "ThirdParty")



SET_PROPERTY(TARGET Box2D  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET glm  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET ImGui  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET SDL2-static  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET SDL2main  PROPERTY FOLDER "ThirdParty")

SET_PROPERTY(TARGET stb  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET yaml-cpp  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET TextEditor  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET ImNodes  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET lua  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET angelscript  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET tgaimage  PROPERTY FOLDER "ThirdParty")
if(WIN32)
SET_PROPERTY(TARGET zlib  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET zlibstatic  PROPERTY FOLDER "ThirdParty")
endif()
SET_PROPERTY(TARGET IrrXML  PROPERTY FOLDER "ThirdParty")
SET_PROPERTY(TARGET assimp  PROPERTY FOLDER "ThirdParty")