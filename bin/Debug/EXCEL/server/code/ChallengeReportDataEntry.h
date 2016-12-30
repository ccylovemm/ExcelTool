// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ChallengeReportDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _CHALLENGEREPORTDATALOADER_H
#define _CHALLENGEREPORTDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ChallengeReportDataEntry
{
	ChallengeReportDataEntry() : id(0){}
	virtual ~ChallengeReportDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	世界赢
	**/
	string	worldWin;

	/**
	世界败
	**/
	string	worldLose;

	/**
	前三名
	**/
	string	worldTop;

	/**
	自己赢
	**/
	string	selfWin;

	/**
	自己败
	**/
	string	selfLose;

	/**
	自己被赢
	**/
	string	selfBeWin;

	/**
	自己被败
	**/
	string	selfBeLose;
}; // ChallengeReportDataEntry define end

//data visitor for the excel table
template <typename T>
class ChallengeReportDataEntryVisitor
{
public:
	ChallengeReportDataEntryVisitor(){ static_assert(std::is_base_of<ChallengeReportDataEntry, T>::value != 0, "T must be inherited from ChallengeReportDataEntry"); }
	virtual ~ChallengeReportDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ChallengeReportDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ChallengeReportDataLoader(){ static_assert(std::is_base_of<ChallengeReportDataEntry, T>::value != 0, "T must be inherited from ChallengeReportDataEntry"); }
	~ChallengeReportDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "worldWin", pData->worldWin);
			doc.GetAttribute(pDataElem, "worldLose", pData->worldLose);
			doc.GetAttribute(pDataElem, "worldTop", pData->worldTop);
			doc.GetAttribute(pDataElem, "selfWin", pData->selfWin);
			doc.GetAttribute(pDataElem, "selfLose", pData->selfLose);
			doc.GetAttribute(pDataElem, "selfBeWin", pData->selfBeWin);
			doc.GetAttribute(pDataElem, "selfBeLose", pData->selfBeLose);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(ChallengeReportDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif

