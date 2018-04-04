#pragma once
#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

namespace px
{
	class Camera
	{
	public:
		Camera();
		Camera(const Vector3 & camPosition = Vector3(0.0f, 0.0f, -2.0f), const Vector3 & camTarget = Vector3(0.0f, 0.0f, -1.f),
			   const Vector3 & camUp = Vector3(0.0f, 1.0f, 0.0f), float speed = 250.0f, float sensitivity = 0.2f);
		~Camera() = default;
		void Update(float dt);

	public:
		void SetPosition(const Vector3 & position);
		void SetFOV(const float & angle);
		void SetYaw(const float & yaw);
		void SetPitch(const float & pitch);

	public:
		Matrix GetViewMatrix() const;
		Matrix GetViewProjectionMatrix() const;
		Matrix GetProjectionMatrix() const;
		Vector3 GetPosition() const;
		float GetFOV() const;
		float GetYaw() const;
		float GetPitch() const;

	private:
		void MoveCamera(float dt);
		void RotateCamera();

	private:
		Vector3 m_cameraPos;
		Vector3 m_camTarget;
		Vector3 m_camUp;
		Matrix m_rotationMatrix;
		Matrix m_viewMatrix;

	private:
		Vector2 m_currentMousePos;
		Vector2 m_lastMousePos;
		float m_camYaw;
		float m_camPitch;
		float m_movementSpeed;
		float m_mouseSensivity;
		float m_fov;
	};
}



