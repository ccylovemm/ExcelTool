// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     CopyGroupDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _COPYGROUPDATALOADER_H
#define _COPYGROUPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct CopyGroupDataEntry
{
	CopyGroupDataEntry() : groupId(0){}
	virtual ~CopyGroupDataEntry(){ }
	virtual UInt32 GetKey() const { return groupId; }
	/**
	副本组id
	**/
	UInt32	groupId;

	/**
	星级列表
	**/
	string	starList;

	/**
	星级对应的宝箱掉落列表
	**/
	string	boxDrop;
}; // CopyGroupDataEntry define end

//data visitor for the excel table
template <typename T>
class CopyGroupDataEntryVisitor
{
public:
	CopyGroupDataEntryVisitor(){ static_assert(std::is_base_of<CopyGroupDataEntry, T>::value != 0, "T must be inherited from CopyGroupDataEntry"); }
	virtual ~CopyGroupDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class CopyGroupDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	CopyGroupDataLoader(){ static_assert(std::is_base_of<CopyGroupDataEntry, T>::value != 0, "T must be inherited from CopyGroupDataEntry"); }
	~CopyGroupDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "groupId", pData->groupId);
			doc.GetAttribute(pDataElem, "starList", pData->starList);
			doc.GetAttribute(pDataElem, "boxDrop", pData->boxDrop);
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

	void VisitData(CopyGroupDataEntryVisitor<T>& visitor)
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

