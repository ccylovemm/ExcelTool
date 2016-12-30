// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TrapDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TRAPDATALOADER_H
#define _TRAPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TrapDataEntry
{
	TrapDataEntry() : id(0), type(0), shape(0), radius1(0.f), radius2(0.f), intervalTime(0), directDmg(0), buffid1(0), targetFlag1(0), buffid2(0), targetFlag2(0), buffid3(0), targetFlag3(0), maxTargetNum(0), prevLastTime(0){}
	virtual ~TrapDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	陷阱id
	**/
	UInt32	id;

	/**
	类型
	**/
	UInt8	type;

	/**
	形状
	**/
	UInt8	shape;

	/**
	圆的半径或者矩形的高
	**/
	Real32	radius1;

	/**
	矩形的宽
	**/
	Real32	radius2;

	/**
	持续陷阱伤害心跳间隔
	**/
	UInt32	intervalTime;

	/**
	直接伤害
	**/
	UInt32	directDmg;

	/**
	buffid
	**/
	UInt16	buffid1;

	/**
	目标类型掩码
	**/
	UInt16	targetFlag1;

	/**
	buffid
	**/
	UInt16	buffid2;

	/**
	目标类型掩码
	**/
	UInt16	targetFlag2;

	/**
	buffid
	**/
	UInt16	buffid3;

	/**
	目标类型掩码
	**/
	UInt16	targetFlag3;

	/**
	目标数量上限
	**/
	UInt32	maxTargetNum;

	/**
	预览特效持续时间
	**/
	UInt32	prevLastTime;
}; // TrapDataEntry define end

//data visitor for the excel table
template <typename T>
class TrapDataEntryVisitor
{
public:
	TrapDataEntryVisitor(){ static_assert(std::is_base_of<TrapDataEntry, T>::value != 0, "T must be inherited from TrapDataEntry"); }
	virtual ~TrapDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TrapDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TrapDataLoader(){ static_assert(std::is_base_of<TrapDataEntry, T>::value != 0, "T must be inherited from TrapDataEntry"); }
	~TrapDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "shape", pData->shape);
			doc.GetAttribute(pDataElem, "radius1", pData->radius1);
			doc.GetAttribute(pDataElem, "radius2", pData->radius2);
			doc.GetAttribute(pDataElem, "intervalTime", pData->intervalTime);
			doc.GetAttribute(pDataElem, "directDmg", pData->directDmg);
			doc.GetAttribute(pDataElem, "buffid1", pData->buffid1);
			doc.GetAttribute(pDataElem, "targetFlag1", pData->targetFlag1);
			doc.GetAttribute(pDataElem, "buffid2", pData->buffid2);
			doc.GetAttribute(pDataElem, "targetFlag2", pData->targetFlag2);
			doc.GetAttribute(pDataElem, "buffid3", pData->buffid3);
			doc.GetAttribute(pDataElem, "targetFlag3", pData->targetFlag3);
			doc.GetAttribute(pDataElem, "maxTargetNum", pData->maxTargetNum);
			doc.GetAttribute(pDataElem, "prevLastTime", pData->prevLastTime);
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

	void VisitData(TrapDataEntryVisitor<T>& visitor)
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

