// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     BuffDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _BUFFDATALOADER_H
#define _BUFFDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct BuffDataEntry
{
	BuffDataEntry() : id(0), group(0), goodtype(0), canceltype(0), effectid(0), effectparams1(0), effectparams2(0), effectparams3(0), triggerbuff(0), maxlasttime(0), maxvalue(0), icon(0), haseffect(0){}
	virtual ~BuffDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	BUFFID
	**/
	UInt32	id;

	/**
	组别
	**/
	UInt8	group;

	/**
	益害类型
	**/
	UInt8	goodtype;

	/**
	中途取消方式
	**/
	UInt8	canceltype;

	/**
	效果函数1
	**/
	UInt8	effectid;

	/**
	参数1
	**/
	UInt32	effectparams1;

	/**
	参数2
	**/
	UInt32	effectparams2;

	/**
	参数3
	**/
	UInt32	effectparams3;

	/**
	buff消失时触发buffid
	**/
	UInt32	triggerbuff;

	/**
	最大累加时间
	**/
	UInt32	maxlasttime;

	/**
	最大累加效果值
	**/
	UInt32	maxvalue;

	/**
	buffICON
	**/
	UInt32	icon;

	/**
	buff特效id
	**/
	UInt16	haseffect;
}; // BuffDataEntry define end

//data visitor for the excel table
template <typename T>
class BuffDataEntryVisitor
{
public:
	BuffDataEntryVisitor(){ static_assert(std::is_base_of<BuffDataEntry, T>::value != 0, "T must be inherited from BuffDataEntry"); }
	virtual ~BuffDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class BuffDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	BuffDataLoader(){ static_assert(std::is_base_of<BuffDataEntry, T>::value != 0, "T must be inherited from BuffDataEntry"); }
	~BuffDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "group", pData->group);
			doc.GetAttribute(pDataElem, "goodtype", pData->goodtype);
			doc.GetAttribute(pDataElem, "canceltype", pData->canceltype);
			doc.GetAttribute(pDataElem, "effectid", pData->effectid);
			doc.GetAttribute(pDataElem, "effectparams1", pData->effectparams1);
			doc.GetAttribute(pDataElem, "effectparams2", pData->effectparams2);
			doc.GetAttribute(pDataElem, "effectparams3", pData->effectparams3);
			doc.GetAttribute(pDataElem, "triggerbuff", pData->triggerbuff);
			doc.GetAttribute(pDataElem, "maxlasttime", pData->maxlasttime);
			doc.GetAttribute(pDataElem, "maxvalue", pData->maxvalue);
			doc.GetAttribute(pDataElem, "icon", pData->icon);
			doc.GetAttribute(pDataElem, "haseffect", pData->haseffect);
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

	void VisitData(BuffDataEntryVisitor<T>& visitor)
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

