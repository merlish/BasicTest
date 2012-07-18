//
//  fakehaskell.c
//  BasicTest
//
//  Created by merlyn on 19/07/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "export.h"

void fakeHaskell()
{
    DemoApp* da = initDemo();
    
    Ogre::SceneManager* sm = getSceneManager();
    Ogre::SceneNode* rnode = getRootSceneNode(sm);
    
    /*	OgreFramework::getSingletonPtr()->m_pSceneMgr->setSkyBox(true, "Examples/SpaceSkyBox");
     
     m_pCubeEntity = OgreFramework::getSingletonPtr()->m_pSceneMgr->createEntity("Cube", "ogrehead.mesh");
     m_pCubeNode = OgreFramework::getSingletonPtr()->m_pSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode");
     m_pCubeNode->attachObject(m_pCubeEntity);
     
     m_pCube2E = OgreFramework::getSingletonPtr()->m_pSceneMgr->createEntity("Steve", Ogre::SceneManager::PT_CUBE);
     m_pCube2N = OgreFramework::getSingletonPtr()->m_pSceneMgr->getRootSceneNode()->createChildSceneNode("SteveN");
     m_pCube2N->attachObject(m_pCube2E);*/
    
    setSkybox(sm, true, "Examples/SpaceSkyBox");
    
    Ogre::Entity* cubeEntity = createEntity(sm, "Cube", "ogrehead.mesh");
    Ogre::SceneNode* cubeNode = createChildSceneNode(rnode, "CubeNode");
    attachObject(cubeNode, cubeEntity);
    
    finishSetupAndRun(da);
}