/***********************************************
Name����Ч������
Desc��SimpleAudioEngine��װ
Auth��Cool.Cat@2013-03-18
***********************************************/
#pragma once
#include "SIX_EntityMgr.h"
#include <SimpleAudioEngine.h>

USING_NS_CC;
using namespace CocosDenshion;

//INTERFACE_BEGIN_BASED(SIX_SoundData,SIX_Interface)
//	CONSTRUCTOR(
//		SIX_SoundData,
//		m_Id = 0;
//		m_IsPreload = false;
//	)
//	// Ψһ����
//	CC_SYNTHESIZE(unsigned int,m_Id,Id);
//	// ���·��
//	CC_SYNTHESIZE(CCString,m_Path,Path);
//	// ��Ч����
//	CC_SYNTHESIZE(SOUND_TYPE,m_Type,Type);
//	// �Ƿ���Ԥ����
//	CC_SYNTHESIZE(bool,m_IsPreload,IsPreload);
//INTERFACE_END()

class SIX_SoundData:public SIX_Interface{
public:
	SIX_SoundData()
	{
		m_Id = 0;
		m_IsPreload = false;	
	}
public:
	// Ψһ����
	virtual unsigned int getId()		{return m_Id;}
	virtual void setId(unsigned int Id)	{m_Id=Id;}

	// ���·��
	virtual CCString getPath()			{return m_Path;}
	virtual void setPath(CCString Path)	{m_Path=Path;}

	// ��Ч����
	virtual int getType()			{return m_Type;}
	virtual void setType(int Type)	{m_Type=Type;}

	// �Ƿ���Ԥ����
	virtual bool getIsPreload()					{return m_IsPreload;}
	virtual void setIsPreload(bool IsPreload)	{m_IsPreload=IsPreload;}
public:
	unsigned int m_Id;
	CCString m_Path;
	int m_Type;
	bool m_IsPreload;
};

class SIX_MusicMgr:public SIX_EntityMgr,public TSingleton<SIX_MusicMgr>{
	//CONSTRUCTOR(
	//	SIX_MusicMgr,
	//	m_AudioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	//	m_SoundList = new SIX_DSTPL<SIX_SoundData>;
	//	m_BgCount = 0;
	//	m_EffectCount = 0;
	//);
	//DESTRUCTOR(
	//	SIX_MusicMgr,
	//	Release();
	//	CC_SAFE_DELETE(m_SoundList);
	//	m_AudioEngine->end();
	//);
public:
	SIX_MusicMgr()
	{
		m_AudioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
		//m_SoundList = new SIX_DSTPL<SIX_SoundData>;
		m_BgCount = 0;
		m_EffectCount = 0;	
	}
	~SIX_MusicMgr()
	{
		Release();
		//CC_SAFE_DELETE(m_SoundList);
		m_AudioEngine->end();
	}
public:
	void ParseNode(SIX_XmlDataSet *pDataSet,const char *nodeName);
	virtual int ParseXML(SIX_DSTPL<SIX_XmlDataSet> *pXmlDataSet);
	virtual int Run();
	virtual int Release();
public:
	void SetSoundResourceFolder(const char *folder)		{m_SoundBasePath = CCString::create(folder);}
	unsigned int GetTotalSoundCount()					{return this->GetObjCount();}
	unsigned int GetBgSoundCount()						{return m_BgCount;}
	unsigned int GetEffectSoundCount()					{return m_EffectCount;}
public:
    // ����
    void preloadBackgroundMusic(unsigned int nSoundId);
    void playBackgroundMusic(unsigned int nSoundId, bool bLoop);
    void playBackgroundMusic(unsigned int nSoundId);
    void stopBackgroundMusic(bool bReleaseData);
    void stopBackgroundMusic();
    void pauseBackgroundMusic();
    void resumeBackgroundMusic();
    void rewindBackgroundMusic();
    bool willPlayBackgroundMusic();
    bool isBackgroundMusicPlaying();
    float getBackgroundMusicVolume();
    void setBackgroundMusicVolume(float volume);
	// ��Ч
    float getEffectsVolume();
    void setEffectsVolume(float volume);
    unsigned int playEffect(unsigned int nSoundId, bool bLoop);
    unsigned int playEffect(unsigned int nSoundId);
    void pauseEffect(unsigned int nSoundId);
    void pauseAllEffects();
    void resumeEffect(unsigned int nSoundId);
    void resumeAllEffects();
    void stopEffect(unsigned int nSoundId);
    void stopAllEffects();
    void preloadEffect(unsigned int nSoundId);
    void unloadEffect(unsigned int nSoundId,bool bDel=false);
public:
	SimpleAudioEngine *m_AudioEngine;
	//SIX_DSTPL<SIX_SoundData> *m_SoundList;
	CCString *m_SoundBasePath;
	unsigned int m_BgCount;
	unsigned int m_EffectCount;
};