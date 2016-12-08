#pragma once
//-----------------------------------------------------------------------------
// CameraComponent Header Includes
//-----------------------------------------------------------------------------
#include "../entityx/Component.h"
#include "Core/math/math_includes.h"
#include "Core/common/basetypes.hpp"

//-----------------------------------------------------------------------------
// Forward Declarations
//-----------------------------------------------------------------------------
enum class ProjectionMode : std::uint32_t;
class Camera;
struct FrameBuffer;

using namespace entityx;
//-----------------------------------------------------------------------------
// Main Class Declarations
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//  Name : CameraComponent (Class)
/// <summary>
/// Class that contains our core Camera data, used for rendering and other things.
/// </summary>
//-----------------------------------------------------------------------------
class CameraComponent : public Component
{
	COMPONENT(CameraComponent)
	SERIALIZABLE(CameraComponent)
	REFLECTABLE(CameraComponent, Component)
public:
	//-------------------------------------------------------------------------
	// Constructors & Destructors
	//-------------------------------------------------------------------------
	CameraComponent();
	CameraComponent(const CameraComponent& camera);
	virtual ~CameraComponent();

	//-------------------------------------------------------------------------
	// Public Methods
	//-------------------------------------------------------------------------
	//-----------------------------------------------------------------------------
	//  Name : setFieldOfView ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& setFieldOfView(float fovDegrees);

	//-----------------------------------------------------------------------------
	//  Name : setNearClip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& setNearClip(float distance);

	//-----------------------------------------------------------------------------
	//  Name : setFarClip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& setFarClip(float distance);

	//-----------------------------------------------------------------------------
	//  Name : setProjectionMode ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	CameraComponent& setProjectionMode(ProjectionMode mode);

	//-----------------------------------------------------------------------------
	//  Name : getFieldOfView ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float getFieldOfView() const;

	//-----------------------------------------------------------------------------
	//  Name : getNearClip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float getNearClip() const;

	//-----------------------------------------------------------------------------
	//  Name : getFarClip ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float getFarClip() const;

	//-----------------------------------------------------------------------------
	//  Name : getProjectionMode ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	ProjectionMode getProjectionMode() const;

	//-----------------------------------------------------------------------------
	//  Name : getCamera ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline Camera& getCamera() { return *mCamera.get(); }

	//-----------------------------------------------------------------------------
	//  Name : getCamera ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	inline const Camera& getCamera() const { return *mCamera.get(); }
	//-----------------------------------------------------------------------------
	//  Name : getRenderSurface ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	std::shared_ptr<FrameBuffer> getOutputBuffer() const;

	//-----------------------------------------------------------------------------
	//  Name : getGBuffer ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	std::shared_ptr<FrameBuffer> getGBuffer() const;
	
	//-----------------------------------------------------------------------------
	//  Name : updateInternal ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void updateInternal(const math::transform& t);

	//-----------------------------------------------------------------------------
	//  Name : getHDR ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	bool getHDR() const;

	//-----------------------------------------------------------------------------
	//  Name : setHDR ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void setHDR(bool hdr);

	//-----------------------------------------------------------------------------
	//  Name : setViewportSize ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void setViewportSize(const uSize& size);

	//-----------------------------------------------------------------------------
	//  Name : getViewportSize ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	const uSize& getViewportSize() const;

	//-----------------------------------------------------------------------------
	//  Name : setProjectionWindow ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void setProjectionWindow();

	//-----------------------------------------------------------------------------
	//  Name : getOrthographicSize ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float getOrthographicSize() const;

	//-----------------------------------------------------------------------------
	//  Name : setPixelsPerUnit ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void setOrthographicSize(float size);

	//-----------------------------------------------------------------------------
	//  Name : getPixelsPerUnit ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	float getPixelsPerUnit() const;

private:
	//-----------------------------------------------------------------------------
	//  Name : init ()
	/// <summary>
	/// 
	/// 
	/// 
	/// </summary>
	//-----------------------------------------------------------------------------
	void init(const uSize& size);
	//-------------------------------------------------------------------------
	// Private Member Variables.
	//-------------------------------------------------------------------------
	/// The camera object this component represents
	std::unique_ptr<Camera> mCamera;
	/// The render surface of this camera
	std::shared_ptr<FrameBuffer> mOutputBuffer;
	/// The g-buffer for this camera.
	std::shared_ptr<FrameBuffer> mGBuffer;
	/// Is the camera HDR?
	bool mHDR = true;
};