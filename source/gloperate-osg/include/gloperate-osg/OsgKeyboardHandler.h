#pragma once


#include <osg/ref_ptr>

#include <gloperate/input/KeyboardInputHandler.h>

#include <gloperate-osg/gloperate-osg_api.h>


namespace osgViewer 
{
    class GraphicsWindowEmbedded;
}


namespace gloperate_osg
{

class OsgRenderStage;


/**
*  @brief
*    Input handler that transfers keyboard events to OSG
*/
class GLOPERATE_OSG_API OsgKeyboardHandler : public gloperate::KeyboardInputHandler
{
public:
    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] embedded
    *    Interface that acts like a window to OSG
    *  @param[in] stage
    *    Render stage that is informed about changes, can be null
    */
    OsgKeyboardHandler(osgViewer::GraphicsWindowEmbedded * embedded, OsgRenderStage * stage = nullptr);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~OsgKeyboardHandler();

    virtual void onKeyDown(gloperate::Key key) override;
    virtual void onKeyUp(gloperate::Key key) override;

protected:
    osgViewer::GraphicsWindowEmbedded * m_embedded; /**< Interface that acts like a window to OSG */
    OsgRenderStage                    * m_stage;    /**< Render stage to which the input handler belongs (can be null) */
};

} // namespace gloperate_osg
