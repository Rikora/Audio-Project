#pragma once
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include <map>
#include <string>
#include <vector>
#include <d3d11.h>
#include <SimpleMath.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;

namespace px
{
	namespace Sound
	{
		enum ID
		{
			Birds,
			Gun
		};
	}

	class SoundManager
	{
	public:
		SoundManager();
		~SoundManager();

	private:
		struct SoundInfo
		{
			FMOD::Sound* sound;
			std::string filePath;
		};

	public:
		void Update();
		void LoadBank(const std::string & strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
		void LoadEvent(const std::string & strEventName);
		void LoadSound(const Sound::ID & id, const std::string & strSoundName, bool b3d = true, bool bLooping = false, bool bStream = false);
		void UnloadSound(const Sound::ID & id);

	public:
		int Play(const Sound::ID & id, const Vector3 & vPos = Vector3(0.f), float fVolumedB = 0.f);
		void PlayEvent(const std::string & strEventName);
		//void StopChannel(int nChannelId);
		void StopEvent(const std::string & strEventName, bool bImmediate = false);

	public:
		//void Set3dListenerAndOrientation(const Vector3& vPosition, const Vector3& vLook, const Vector3& vUp);
		void SetEventParameter(const std::string & strEventName, const std::string & strParameterName, float fValue);
		//void StopAllChannels();
		void SetChannel3dPosition(int nChannelId, const Vector3 & vPosition);
		void SetChannelVolume(int nChannelId, float fVolumedB);
		
	public:
		void GetEventParameter(const std::string & strEventName, const std::string & strEventParameter, float* parameter);
		//bool IsPlaying(int nChannelId) const;
		bool IsEventPlaying(const std::string & strEventName) const;

	public:
		float dbToVolume(float dB);
		float VolumeTodB(float volume);
		FMOD_VECTOR VectorToFmod(const Vector3& vPosition);	

	private:
		int ErrorCheck(FMOD_RESULT result);

	private:
		FMOD::Studio::System* m_studioSystem;
		FMOD::System* m_system;
		int m_nextChannelId;

	private:
		std::map<std::string, FMOD::Studio::Bank*> m_banks;
		std::map<std::string, FMOD::Studio::EventInstance*> m_events;
		std::map<Sound::ID, SoundInfo> m_sounds;
		using Channels = std::map<int, FMOD::Channel*>;
		Channels m_channels;
	};
}
