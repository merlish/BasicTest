{-# LANGUAGE ForeignFunctionInterface #-}
import Foreign.C
import Foreign.Ptr
import System.Directory

data DemoApp = DemoApp
data SceneManager = SceneManager
data Entity = Entity
data SceneNode = SceneNode

boolToCUChar :: Bool -> CUChar
boolToCUChar False = 0
boolToCUChar True = 1


foreign import ccall "export.h initDemo"
    c_initDemo :: IO (Ptr DemoApp)

foreign import ccall "export.h getSceneManager"
    c_getSceneManager :: IO (Ptr SceneManager)

foreign import ccall "export.h setSkybox"
    c_setSkybox :: (Ptr SceneManager) -> CUChar -> CString -> IO ()

foreign import ccall "export.h getRootSceneNode"
    c_getRootSceneNode :: (Ptr SceneManager) -> IO (Ptr SceneNode)

foreign import ccall "export.h createEntity"
    c_createEntity :: (Ptr SceneManager) -> CString -> CString -> IO (Ptr Entity)

foreign import ccall "export.h createChildSceneNode"
    c_createChildSceneNode :: (Ptr SceneNode) -> CString -> IO (Ptr SceneNode)

-- ehh, fudging the type a little.
-- second param is actually Ogre::MovableObject*, from which Ogre::Entity* derives.
foreign import ccall "export.h attachObject"
    c_attachObject :: (Ptr SceneNode) -> (Ptr Entity) -> IO ()

foreign import ccall "export.h finishSetupAndRun"
    c_finishSetupAndRun :: (Ptr DemoApp) -> IO ()

initDemo = c_initDemo
getSceneManager = c_getSceneManager
-- withCString automatically frees string mem after provided subcomputation completes.
setSkybox sceneMgrPtr enable filename = withCString filename (c_setSkybox sceneMgrPtr (boolToCUChar enable))
getRootSceneNode = c_getRootSceneNode

createEntity :: (Ptr SceneManager) -> String -> String -> IO (Ptr Entity)
createEntity smp name filename = withCString filename (\cfilename -> withCString name (\cname -> c_createEntity smp cname cfilename))

createChildSceneNode parent name = withCString name (c_createChildSceneNode parent)
attachObject = c_attachObject
finishSetupAndRun = c_finishSetupAndRun

main = do
  putStrLn "Hey, listen!"
  putStrLn " initDemo ::"
  demoAppPtr <- initDemo
  putStrLn " getSceneManager ::"
  sceneManagerPtr <- getSceneManager
  putStrLn " setSkybox ::"
  setSkybox sceneManagerPtr True "Examples/SpaceSkyBox"

  putStrLn " getRootSceneNode ::"
  rootNodePtr <- getRootSceneNode sceneManagerPtr

  -- Ogre::Entity* headEntity = createEntity(sm, "Head", "ogrehead.mesh");
  -- Ogre::SceneNode* headNode = createChildSceneNode(rootNode, "Head");
  -- attachObject(headNode, headEntity);
  -- (please note that the fact that both the entity and the node are called 'Head' doesn't affect anything.)
  -- (entity names just have to be unique amongst entities, and node names unique amongst nodes.
  --  no other notable constraints exist.)
  putStrLn " createEntity ::"
  headEntPtr <- createEntity sceneManagerPtr "Head" "ogrehead.mesh"
  putStrLn " createChildSceneNode ::"
  headNodePtr <- createChildSceneNode rootNodePtr "Head"
  putStrLn " attachObject ::"
  attachObject headNodePtr headEntPtr

  putStrLn " c_finishSetupAndRun ::"
  c_finishSetupAndRun demoAppPtr
  putStrLn "^^^"
  

