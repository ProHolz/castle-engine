{ -*- buffer-read-only: t -*-

  Copyright 2015-2023 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal }

{$ifdef read_interface}

  strict private
    function GetColor: TAbstractColorNode;
    procedure SetColor(const Value: TAbstractColorNode);
    function GetCoord: TAbstractCoordinateNode;
    procedure SetCoord(const Value: TAbstractCoordinateNode);
{$ifndef CASTLE_SLIM_NODES}
    function GetFogCoord: TFogCoordinateNode;
    procedure SetFogCoord(const Value: TFogCoordinateNode);
{$endif not CASTLE_SLIM_NODES}
    function GetNormal: TAbstractNormalNode;
    procedure SetNormal(const Value: TAbstractNormalNode);
    function GetTangent: TTangentNode;
    procedure SetTangent(const Value: TTangentNode);
    function GetTexCoord: TAbstractTextureCoordinateNode;
    procedure SetTexCoord(const Value: TAbstractTextureCoordinateNode);
    function GetCcw: Boolean;
    procedure SetCcw(const Value: Boolean);
    function GetColorPerVertex: Boolean;
    procedure SetColorPerVertex(const Value: Boolean);
    function GetNormalPerVertex: Boolean;
    procedure SetNormalPerVertex(const Value: Boolean);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdAttrib: TMFNode;
    { Internal wrapper for property @link(Attrib). This wrapper API may change, we advise to access simpler @link(Attrib) instead. }
    public property FdAttrib: TMFNode read FFdAttrib;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetAttrib(const Value: array of TAbstractVertexAttributeNode);
{$endif not CASTLE_SLIM_NODES}

    strict private FFdColor: TSFNode;
    { Internal wrapper for property @link(Color). This wrapper API may change, we advise to access simpler @link(Color) instead. }
    public property FdColor: TSFNode read FFdColor;
    {  }
    property Color: TAbstractColorNode read GetColor write SetColor;

    strict private FFdCoord: TSFNode;
    { Internal wrapper for property @link(Coord). This wrapper API may change, we advise to access simpler @link(Coord) instead. }
    public property FdCoord: TSFNode read FFdCoord;
    {  }
    property Coord: TAbstractCoordinateNode read GetCoord write SetCoord;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdFogCoord: TSFNode;
    { Internal wrapper for property @link(FogCoord). This wrapper API may change, we advise to access simpler @link(FogCoord) instead. }
    public property FdFogCoord: TSFNode read FFdFogCoord;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    property FogCoord: TFogCoordinateNode read GetFogCoord write SetFogCoord;
{$endif not CASTLE_SLIM_NODES}

    strict private FFdNormal: TSFNode;
    { Internal wrapper for property @link(Normal). This wrapper API may change, we advise to access simpler @link(Normal) instead. }
    public property FdNormal: TSFNode read FFdNormal;
    {  }
    property Normal: TAbstractNormalNode read GetNormal write SetNormal;

    strict private FFdTangent: TSFNode;
    { Internal wrapper for property @link(Tangent). This wrapper API may change, we advise to access simpler @link(Tangent) instead. }
    public property FdTangent: TSFNode read FFdTangent;
    { Tangent vectors describe the tangent coordinate-space, used by the bump mapping algorithm. If specified, the ordering of tangents should be the same as normals, i.e. they should follow the NormalPerVertex and such properties. }
    property Tangent: TTangentNode read GetTangent write SetTangent;

    strict private FFdTexCoord: TSFNode;
    { Internal wrapper for property @link(TexCoord). This wrapper API may change, we advise to access simpler @link(TexCoord) instead. }
    public property FdTexCoord: TSFNode read FFdTexCoord;
    {  }
    property TexCoord: TAbstractTextureCoordinateNode read GetTexCoord write SetTexCoord;

    strict private FFdCcw: TSFBool;
    { Internal wrapper for property @link(Ccw). This wrapper API may change, we advise to access simpler @link(Ccw) instead. }
    public property FdCcw: TSFBool read FFdCcw;
    {  }
    property Ccw: Boolean read GetCcw write SetCcw;

    strict private FFdColorPerVertex: TSFBool;
    { Internal wrapper for property @link(ColorPerVertex). This wrapper API may change, we advise to access simpler @link(ColorPerVertex) instead. }
    public property FdColorPerVertex: TSFBool read FFdColorPerVertex;
    {  }
    property ColorPerVertex: Boolean read GetColorPerVertex write SetColorPerVertex;

    strict private FFdNormalPerVertex: TSFBool;
    { Internal wrapper for property @link(NormalPerVertex). This wrapper API may change, we advise to access simpler @link(NormalPerVertex) instead. }
    public property FdNormalPerVertex: TSFBool read FFdNormalPerVertex;
    {  }
    property NormalPerVertex: Boolean read GetNormalPerVertex write SetNormalPerVertex;

    strict private FFdSolid: TSFBool;
    { Internal wrapper for property @link(Solid). This wrapper API may change, we advise to access simpler @link(Solid) instead. }
    public property FdSolid: TSFBool read FFdSolid;

{$ifndef CASTLE_SLIM_NODES}
    strict private FFdRadianceTransfer: TMFVec3f;
    { Internal wrapper for property @link(RadianceTransfer). This wrapper API may change, we advise to access simpler @link(RadianceTransfer) instead. }
    public property FdRadianceTransfer: TMFVec3f read FFdRadianceTransfer;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetRadianceTransfer(const Value: array of TVector3); overload;
{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
    {  }
    procedure SetRadianceTransfer(const Value: TVector3List); overload;
{$endif not CASTLE_SLIM_NODES}

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractComposedGeometryNode ----------------------------------------------- }

{$ifndef CASTLE_SLIM_NODES}
procedure TAbstractComposedGeometryNode.SetAttrib(const Value: array of TAbstractVertexAttributeNode);
var
  L: Integer;
  A: array of TX3DNode;
begin
  L := High(Value) + 1;
  SetLength(A, L);
  if L > 0 then
    Move(Value[0], A[0], L * SizeOf(TAbstractVertexAttributeNode));
  FdAttrib.Send(A);
end;

{$endif not CASTLE_SLIM_NODES}
function TAbstractComposedGeometryNode.GetColor: TAbstractColorNode;
begin
  if FdColor.Value is TAbstractColorNode then
    Result := TAbstractColorNode(FdColor.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetColor(const Value: TAbstractColorNode);
begin
  FdColor.Send(Value);
end;

function TAbstractComposedGeometryNode.GetCoord: TAbstractCoordinateNode;
begin
  if FdCoord.Value is TAbstractCoordinateNode then
    Result := TAbstractCoordinateNode(FdCoord.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetCoord(const Value: TAbstractCoordinateNode);
begin
  FdCoord.Send(Value);
end;

{$ifndef CASTLE_SLIM_NODES}
function TAbstractComposedGeometryNode.GetFogCoord: TFogCoordinateNode;
begin
  if FdFogCoord.Value is TFogCoordinateNode then
    Result := TFogCoordinateNode(FdFogCoord.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetFogCoord(const Value: TFogCoordinateNode);
begin
  FdFogCoord.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
function TAbstractComposedGeometryNode.GetNormal: TAbstractNormalNode;
begin
  if FdNormal.Value is TAbstractNormalNode then
    Result := TAbstractNormalNode(FdNormal.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetNormal(const Value: TAbstractNormalNode);
begin
  FdNormal.Send(Value);
end;

function TAbstractComposedGeometryNode.GetTangent: TTangentNode;
begin
  if FdTangent.Value is TTangentNode then
    Result := TTangentNode(FdTangent.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetTangent(const Value: TTangentNode);
begin
  FdTangent.Send(Value);
end;

function TAbstractComposedGeometryNode.GetTexCoord: TAbstractTextureCoordinateNode;
begin
  if FdTexCoord.Value is TAbstractTextureCoordinateNode then
    Result := TAbstractTextureCoordinateNode(FdTexCoord.Value)
  else
    Result := nil;
end;

procedure TAbstractComposedGeometryNode.SetTexCoord(const Value: TAbstractTextureCoordinateNode);
begin
  SetTexCoordBefore(Value);
  FdTexCoord.Send(Value);
end;

function TAbstractComposedGeometryNode.GetCcw: Boolean;
begin
  Result := FdCcw.Value;
end;

procedure TAbstractComposedGeometryNode.SetCcw(const Value: Boolean);
begin
  FdCcw.Send(Value);
end;

function TAbstractComposedGeometryNode.GetColorPerVertex: Boolean;
begin
  Result := FdColorPerVertex.Value;
end;

procedure TAbstractComposedGeometryNode.SetColorPerVertex(const Value: Boolean);
begin
  FdColorPerVertex.Send(Value);
end;

function TAbstractComposedGeometryNode.GetNormalPerVertex: Boolean;
begin
  Result := FdNormalPerVertex.Value;
end;

procedure TAbstractComposedGeometryNode.SetNormalPerVertex(const Value: Boolean);
begin
  FdNormalPerVertex.Send(Value);
end;

{$ifndef CASTLE_SLIM_NODES}
procedure TAbstractComposedGeometryNode.SetRadianceTransfer(const Value: array of TVector3);
begin
  FdRadianceTransfer.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
{$ifndef CASTLE_SLIM_NODES}
procedure TAbstractComposedGeometryNode.SetRadianceTransfer(const Value: TVector3List);
begin
  FdRadianceTransfer.Send(Value);
end;

{$endif not CASTLE_SLIM_NODES}
class function TAbstractComposedGeometryNode.ClassX3DType: String;
begin
  Result := 'X3DComposedGeometryNode';
end;

procedure TAbstractComposedGeometryNode.CreateNode;
begin
  inherited;

{$ifndef CASTLE_SLIM_NODES}
  FFdAttrib := TMFNode.Create(Self, True, 'attrib', [TAbstractVertexAttributeNode]);
   FdAttrib.ChangeAlways := chGeometry;
  AddField(FFdAttrib);
{$endif not CASTLE_SLIM_NODES}

  FFdColor := TSFNode.Create(Self, True, 'color', [TAbstractColorNode]);
   FdColor.ChangeAlways := chGeometry;
  AddField(FFdColor);

  FFdCoord := TSFNode.Create(Self, True, 'coord', [TAbstractCoordinateNode]);
   FdCoord.ChangeAlways := chGeometry;
  AddField(FFdCoord);

{$ifndef CASTLE_SLIM_NODES}
  FFdFogCoord := TSFNode.Create(Self, True, 'fogCoord', [TFogCoordinateNode]);
   FdFogCoord.ChangeAlways := chGeometry;
  AddField(FFdFogCoord);
{$endif not CASTLE_SLIM_NODES}

  FFdNormal := TSFNode.Create(Self, True, 'normal', [TAbstractNormalNode]);
   FdNormal.ChangeAlways := chGeometry;
  AddField(FFdNormal);

  FFdTangent := TSFNode.Create(Self, True, 'tangent', [TTangentNode]);
   FdTangent.ChangeAlways := chGeometry;
  AddField(FFdTangent);

  FFdTexCoord := TSFNode.Create(Self, True, 'texCoord', [TAbstractTextureCoordinateNode]);
   FdTexCoord.ChangeAlways := chGeometry;
  AddField(FFdTexCoord);

  FFdCcw := TSFBool.Create(Self, False, 'ccw', true);
   FdCcw.ChangeAlways := chGeometry;
  AddField(FFdCcw);

  FFdColorPerVertex := TSFBool.Create(Self, False, 'colorPerVertex', true);
   FdColorPerVertex.ChangeAlways := chGeometry;
  AddField(FFdColorPerVertex);

  FFdNormalPerVertex := TSFBool.Create(Self, False, 'normalPerVertex', true);
   FdNormalPerVertex.ChangeAlways := chGeometry;
  AddField(FFdNormalPerVertex);

  FFdSolid := TSFBool.Create(Self, False, 'solid', true);
   FdSolid.ChangeAlways := chGeometry;
  AddField(FFdSolid);

{$ifndef CASTLE_SLIM_NODES}
  FFdRadianceTransfer := TMFVec3f.Create(Self, True, 'radianceTransfer', []);
   FdRadianceTransfer.ChangeAlways := chGeometry;
  AddField(FFdRadianceTransfer);
{$endif not CASTLE_SLIM_NODES}
end;

{$endif read_implementation}
