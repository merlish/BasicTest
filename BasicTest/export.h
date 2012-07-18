//
//  export.h
//  BasicTest
//
//  Created by merlyn on 18/07/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BasicTest_export_h
#define BasicTest_export_h

#include "OgreDemoApp.h"
#include "OgreFramework.h"

#include <OgreEntity.h>
#include <OgreMovableObject.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

extern "C"
{
    DemoApp* initDemo();
    
    Ogre::SceneManager* getSceneManager();
    
    void setSkybox(Ogre::SceneManager* sceneManager, bool enable, char* filename);
    
    Ogre::SceneNode* getRootSceneNode(Ogre::SceneManager* sceneManager);
    
    Ogre::Entity* createEntity(Ogre::SceneManager* sceneManager, char* name, char* filename);
    
    Ogre::SceneNode* createChildSceneNode(Ogre::SceneNode* parent, char* name);
    
    void attachObject(Ogre::SceneNode* node, Ogre::MovableObject* object);
    
    void finishSetupAndRun(DemoApp* demo);
    
    
}


#endif
