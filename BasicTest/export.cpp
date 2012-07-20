//
//  export.cpp
//  BasicTest
//
//  Created by merlyn on 18/07/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "export.h"

extern "C"
{
    DemoApp* initDemo()
    {
        // var belongs to function; can only call initDemo() once safely.
        DemoApp* d;
        
        try
        {
            d = new DemoApp();
        }
        catch (std::exception& e)
        {
            fprintf(stderr, "An exception occurred in new DemoApp(): %s\n", e.what());
        }
        
        
        try
        {
            d->startDemoPartial();
        }
        catch(std::exception& e)
        {
            fprintf(stderr, "An exception has occurred in d->startDemoPartial(): %s\n", e.what());
        }
        
        return d;
    }
    
    Ogre::SceneManager* getSceneManager()
    {
        return OgreFramework::getSingletonPtr()->m_pSceneMgr;
    }
    
    void setSkybox(Ogre::SceneManager* sceneManager, bool enable, char* filename)
    {
        sceneManager->setSkyBox(enable, filename);
    }
    
    Ogre::SceneNode* getRootSceneNode(Ogre::SceneManager* sceneManager)
    {
        return sceneManager->getRootSceneNode();
    }
    
    Ogre::Entity* createEntity(Ogre::SceneManager* sceneManager, char* name, char* filename)
    {
        return sceneManager->createEntity(name, filename);
    }
    
    Ogre::SceneNode* createChildSceneNode(Ogre::SceneNode* parent, char* name)
    {
        return parent->createChildSceneNode(name);
    }
    
    void attachObject(Ogre::SceneNode* node, Ogre::MovableObject* object)
    {
        node->attachObject(object);
    }
    
    void finishSetupAndRun(DemoApp* demo)
    {
        // sympathy call: i couldn't be bothered to bind stuff for creating the sole light
        demo->setupDemoScene();
        
        // actually run the demo.  this call doesn't return 'til exit time.
        demo->runDemo();
    }

}