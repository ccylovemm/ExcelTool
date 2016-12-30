// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     CollectPoolDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _COLLECTPOOLDATALOADER_H
#define _COLLECTPOOLDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct CollectPoolDataEntry
{
	CollectPoolDataEntry() : id(0), ghostID(0), pictureID(0), volume(0), addPropertyID(0), value(0){}
	virtual ~CollectPoolDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	魂池名
	**/
	string	name;

	/**
	对应妖魂
	**/
	UInt32	ghostID;

	/**
	河图ID
	**/
	UInt32	pictureID;

	/**
	所属线
	**/
	string	line;

	/**
	容量
	**/
	UInt32	volume;

	/**
	集齐增加属性
	**/
	UInt32	addPropertyID;

	/**
	增加数值
	**/
	UInt32	value;
}; // CollectPoolDataEntry define end

//data visitor for the excel table
template <typename T>
class CollectPoolDataEntryVisitor
{
public:
	CollectPoolDataEntryVisitor(){ static_assert(std::is_base_of<CollectPoolDataEntry, T>::value != 0, "T must be inherited from CollectPoolDataEntry"); }
	virtual ~CollectPoolDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class CollectPoolDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	CollectPoolDataLoader(){ static_assert(std::is_base_of<CollectPoolDataEntry, T>::value != 0, "T must be inherited from CollectPoolDataEntry"); }
	~CollectPoolDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "ghostID", pData->ghostID);
			doc.GetAttribute(pDataElem, "pictureID", pData->pictureID);
			doc.GetAttribute(pDataElem, "line", pData->line);
			doc.GetAttribute(pDataElem, "volume", pData->volume);
			doc.GetAttribute(pDataElem, "addPropertyID", pData->addPropertyID);
			doc.GetAttribute(pDataElem, "value", pData->value);
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

	void VisitData(CollectPoolDataEntryVisitor<T>& visitor)
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

